classdef Composition < handle
    % COMPOSITION High-performance engine for hybrid benchmark functions.
    % This class allows blending multiple base functions using CEC-standard
    % exponential weighting, shifting, and rotation in MATLAB.

    properties
        Components = {}
        ConstantC = 2000.0
        SumMode = false
        UseSqrtWeight = false
    end

    methods
        function obj = Composition(constant_c)
            if nargin > 0
                obj.ConstantC = constant_c;
            end
        end

        function add(obj, fcn, shift, rotation, sigma, lambda, bias, f_max, input_offset, apply_osz, apply_asy)
            % ADD Adds a base function component to the composition.
            %   fcn: function handle or name (e.g., @ackleyfcn or 'ackley')
            %   shift: 1xN vector for shifting the optimum
            %   rotation: NxN matrix for coordinate rotation
            %   sigma, lambda, bias, f_max: scalars
            %   input_offset: 1xN vector added after rotation
            %   apply_osz, apply_asy: booleans

            if ischar(fcn) || isstring(fcn)
                fcn_name = char(fcn);
                % Try to find function with 'fcn' suffix if base name doesn't exist
                if ~exist(fcn_name, 'file') && exist([fcn_name, 'fcn'], 'file')
                    fcn_handle = str2func([fcn_name, 'fcn']);
                else
                    fcn_handle = str2func(fcn_name);
                end
            else
                fcn_handle = fcn;
            end

            n = length(shift);
            if nargin < 4 || isempty(rotation), rotation = eye(n); end
            if nargin < 5 || isempty(sigma), sigma = 1.0; end
            if nargin < 6 || isempty(lambda), lambda = 1.0; end
            if nargin < 7 || isempty(bias), bias = 0.0; end
            if nargin < 8 || isempty(f_max), f_max = 1.0; end
            if nargin < 9 || isempty(input_offset), input_offset = []; end
            if nargin < 10 || isempty(apply_osz), apply_osz = false; end
            if nargin < 11 || isempty(apply_asy), apply_asy = false; end

            new_comp = struct(...
                'fcn', fcn_handle, ...
                'shift', reshape(shift, 1, []), ...
                'rotation', rotation, ...
                'sigma', sigma, ...
                'lambda', lambda, ...
                'bias', bias, ...
                'f_max', f_max, ...
                'input_offset', reshape(input_offset, 1, []), ...
                'apply_osz', apply_osz, ...
                'apply_asy', apply_asy ...
            );

            obj.Components{end+1} = new_comp;
        end

        function scores = evaluate(obj, x)
            [m, n] = size(x);
            num_comp = length(obj.Components);

            if num_comp == 0
                scores = zeros(m, 1);
                return;
            end

            weights = zeros(m, num_comp);
            comp_scores = zeros(m, num_comp);

            for i = 1:num_comp
                comp = obj.Components{i};

                % 1. Shift
                diff = x - repmat(comp.shift, m, 1);
                dists = sum(diff.^2, 2);

                % 2. Weights
                if obj.UseSqrtWeight
                    % Handle zero distances with a large value
                    w = (1.0 ./ (sqrt(dists) + 1e-15)) .* exp(-dists / (2 * n * comp.sigma^2));
                    % If distance is very small, we might get INF.
                    % In C++ we used 1e99, in MATLAB we can use a large number.
                    idx_zero = dists < 1e-15;
                    w(idx_zero) = 1e99;
                    weights(:, i) = w;
                else
                    weights(:, i) = exp(-dists / (2 * n * comp.sigma^2));
                end

                % 3. Transform: z = (x - o) / lambda
                z = diff / comp.lambda;

                if comp.apply_osz
                    z = t_oszfcn(z);
                end
                if comp.apply_asy
                    z = t_asyfcn(z);
                end

                % 4. Rotate
                rotated_z = z * comp.rotation;

                % 5. Offset (after rotation in CEC)
                if ~isempty(comp.input_offset)
                    rotated_z = rotated_z + repmat(comp.input_offset, m, 1);
                end

                % 6. Evaluate base function
                raw_score = comp.fcn(rotated_z);

                % 7. Scale and bias: f' = C * f / f_max + bias
                comp_scores(:, i) = (obj.ConstantC * raw_score / comp.f_max) + comp.bias;
            end

            if obj.SumMode
                scores = sum(comp_scores, 2);
                return;
            end

            weight_sums = sum(weights, 2);

            % Final normalized blending
            scores = sum(weights .* comp_scores, 2) ./ (weight_sums + 1e-300);

            % Safety check for zero weights
            idx = weight_sums == 0;
            if any(idx)
                scores(idx) = comp_scores(idx, 1);
            end
        end
    end
end
