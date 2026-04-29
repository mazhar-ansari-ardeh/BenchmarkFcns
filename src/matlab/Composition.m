classdef Composition < handle
    % COMPOSITION High-performance engine for hybrid benchmark functions.
    % This class allows blending multiple base functions using CEC-standard
    % exponential weighting, shifting, and rotation in MATLAB.

    properties
        Components = {}
        ConstantC = 2000.0
    end

    methods
        function obj = Composition(constant_c)
            if nargin > 0
                obj.ConstantC = constant_c;
            end
        end

        function add(obj, fcn, shift, rotation, sigma, lambda, bias, f_max)
            % ADD Adds a base function component to the composition.
            %   fcn: function handle or name (e.g., @ackleyfcn or 'ackley')
            %   shift: 1xN vector for shifting the optimum
            %   rotation: NxN matrix for coordinate rotation
            %   sigma, lambda, bias, f_max: scalars

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
            if nargin < 4 || isempty(rotation)
                rotation = eye(n);
            end
            if nargin < 5 || isempty(sigma), sigma = 1.0; end
            if nargin < 6 || isempty(lambda), lambda = 1.0; end
            if nargin < 7 || isempty(bias), bias = 0.0; end
            if nargin < 8 || isempty(f_max), f_max = 1.0; end

            new_comp = struct(...
                'fcn', fcn_handle, ...
                'shift', reshape(shift, 1, []), ...
                'rotation', rotation, ...
                'sigma', sigma, ...
                'lambda', lambda, ...
                'bias', bias, ...
                'f_max', f_max ...
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

                % 1. Weights: w_i = exp(-dist / (2 * n * sigma^2))
                diff = x - repmat(comp.shift, m, 1);
                dists = sum(diff.^2, 2);
                weights(:, i) = exp(-dists / (2 * n * comp.sigma^2));

                % 2. Transform: z = (x - o) / lambda * M
                z = diff / comp.lambda;
                rotated_z = z * comp.rotation;

                % 3. Evaluate base function
                raw_score = comp.fcn(rotated_z);

                % 4. Scale and bias: f' = C * f / f_max + bias
                comp_scores(:, i) = (obj.ConstantC * raw_score / comp.f_max) + comp.bias;
            end

            weight_sums = sum(weights, 2);

            % Final normalized blending
            scores = sum(weights .* comp_scores, 2) ./ weight_sums;

            % Safety check for extremely small weights
            idx = weight_sums == 0;
            if any(idx)
                scores(idx) = comp_scores(idx, 1);
            end
        end
    end
end
