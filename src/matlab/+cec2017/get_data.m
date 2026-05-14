function [shift, rotation, shuffle] = get_data(fid, n)
    % GET_DATA Loads shift, rotation, and shuffle data for CEC 2017.

    % Find the data directory relative to this file
    this_path = mfilename('fullpath');
    [matlab_dir, ~, ~] = fileparts(this_path); % +cec2017 folder
    [matlab_root, ~, ~] = fileparts(matlab_dir); % src/matlab
    [src_root, ~, ~] = fileparts(matlab_root); % src
    [project_root, ~, ~] = fileparts(src_root); % project root

    data_dir = fullfile(project_root, 'data', 'cec2017');

    % 1. Load Shift Vector
    shift_file = fullfile(data_dir, sprintf('shift_%d.txt', fid));
    if exist(shift_file, 'file')
        raw_shift = load(shift_file);
        shift = raw_shift(1:n);
    else
        % For Composition functions, we might need multiple shifts.
        % The evaluate function handles this by slicing if we return the whole thing.
        % Actually, cec.cpp loads the whole shift file.
        shift = load(shift_file);
    end

    % 2. Load Rotation Matrix
    rot_file = fullfile(data_dir, sprintf('M_%d_D%d.txt', fid, n));
    if exist(rot_file, 'file')
        rotation = load(rot_file);
    else
        rotation = eye(n);
    end

    % 3. Load Shuffle Vector (for Hybrid functions)
    shuffle = [];
    if fid >= 11 && fid <= 20
        shuf_file = fullfile(data_dir, sprintf('shuffle_%d_D%d.txt', fid, n));
        if exist(shuf_file, 'file')
            shuffle = load(shuf_file);
            % Convert to 1-based indexing for MATLAB
            shuffle = shuffle + 1;
        end
    end
end
