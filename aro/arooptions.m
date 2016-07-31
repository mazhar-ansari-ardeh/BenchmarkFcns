% AROOPTIONS Creates a option structure for ARO.
% OPTIONS = AROOPTIONS returns an option structure that its fields are set
% to the default values. 
% OPTIONS = AROOPTIONS('PARAM',VALUE) creates a structure with the default
% parameters used for all PARAM not specified, and will use the passed
% argument VALUE for the specified PARAM.
% WARNING: Validity of PARAMs are not checked. 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function setting = arooptions(varargin)

   
    if nargin == 0
        setting = struct('InitialParent', [], 'Generations', 200, 'Display', 'off');
        return;
    end
    
    if nargin == 1 
        if ischar(varargin{1}) 
            if strcmpi(varargin{1}, 'default')
                setting = struct('InitialParent', [], 'Generations', 200, 'Display', 'off');
                setting.Generations = 200;
                return
            end
            if strcmpi(varargin{1}, 'list')
                fprintf('InitialParent: [vector]\n');
                fprintf('Generations  : [positive scalar | 200]\n')
                fprintf('Display      : [''off'' | ''iter'' | ''final'']\n')
                return
            end
        end
    end
    
    setting = struct('InitialParent', [], 'Generations', 200, 'Display', 'off');
    % At this moment, the validity of input data is not checked. BAD IDEA!!
    for i = 1:2:nargin
        setting = setfield(setting, varargin{i}, varargin{i + 1});
    end
end