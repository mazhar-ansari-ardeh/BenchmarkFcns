% AROOPTIONS Creates an option structure for Artificial Bee Colony
% algorithm.
% ABCOPTIONS will print the list of available options and their
% values.
% OPTIONS = ABCOPTIONS('default') will return an option structure that
% contains default values for the algorithm parameters.
% OPTIONS = ABCOPTIONS('list') will print the list of available options and
% their values.
% OPTIONS = ABCOPTIONS('PARAM',VALUE) creates a structure with the default
% parameters used for all PARAM not specified, and will use the passed
% argument VALUE for the specified PARAM.
% WARNING: Validity of PARAMs are not checked.
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function setting = abcoptions(varargin)
    if nargin == 0
        fprintf('InitialPopulation  : [matrix]\n');
        fprintf('Generations        : [positive scalar | "200"]\n')
        fprintf('Display            : [''off'' | ''iter'' | ''final'']\n')
        fprintf('PopulationSize     : [positive scalar | "200"]\n');
        fprintf('Limit              : [positive scalar | "10"]\n');
        fprintf('StallLimit         : [positive scalar | "Inf"]\n');
        return
    end

    if nargin == 1
        if ischar(varargin{1})
            if strcmpi(varargin{1}, 'default')
                setting = struct('InitialPopulation', [], ...
                    'Generations', 200, ...
                    'Display', 'off', ...
                    'PopulationSize', 200, ...
                    'Limit', 10, ...
                    'StallLimit', inf);
                return
            end
            if strcmpi(varargin{1}, 'list')
                abcoptions
                return
            end
        end
    end

    setting = struct('InitialPopulation', [], ...
                    'Generations', 200, ...
                    'Display', 'off', ...
                    'PopulationSize', 200, ...
                    'Limit', 10, ...
                    'StallLimit', inf);
    % At this moment, the validity of input data is not checked. BAD IDEA!!
    for i = 1:2:nargin
        setting = setfield(setting, varargin{i}, varargin{i + 1});
    end
end
