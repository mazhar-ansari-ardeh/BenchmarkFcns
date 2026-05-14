function [shift, rotation, shuffle] = get_data(fid, n)
    % GET_DATA Loads shift, rotation, and shuffle data for CEC 2022.

    this_path = mfilename('fullpath');
    [matlab_dir, ~, ~] = fileparts(this_path);
    [matlab_root, ~, ~] = fileparts(matlab_dir);
    [src_root, ~, ~] = fileparts(matlab_root);
    [project_root, ~, ~] = fileparts(src_root);

    data_dir = fullfile(project_root, 'data', 'cec2022');

    % 1. Load Shift Vector
    shift_file = fullfile(data_dir, sprintf('shift_data_%d.txt', fid));
    if exist(shift_file, 'file')
        shift = load(shift_file);
    else
        error('Shift data file not found: %s', shift_file);
    end

    % 2. Load Rotation Matrix
    rot_file = fullfile(data_dir, sprintf('M_%d_D%d.txt', fid, n));
    if exist(rot_file, 'file')
        rotation = load(rot_file);
    else
        rotation = eye(n);
    end

    % 3. Load Shuffle Vector
    shuffle = [];
    shuf_file = fullfile(data_dir, sprintf('shuffle_%d_D%d.txt', fid, n));
    if exist(shuf_file, 'file')
        shuffle = load(shuf_file);
        % Files are already 1-based.
    end
end
