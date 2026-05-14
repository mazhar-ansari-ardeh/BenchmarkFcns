function scores = evaluate(x, fid)
    % EVALUATE Evaluates the CEC 2017 Single-Objective function.
    %   SCORES = EVALUATE(X, FID) evaluates function FID on input X.
    %   X: M-by-N matrix of points.
    %   FID: Function ID (1, 3-30).

    [m, n] = size(x);
    if fid == 2
        error('CEC 2017 F2 was removed.');
    end

    % Get data
    [shift_vec, rotation, permutation] = cec2017.get_data(fid, n);

    if fid <= 10
        % Simple Functions
        comp = Composition(1.0);

        apply_osz = false;
        apply_asy = false;

        switch fid
            case 1, base_name = 'bentcigar'; apply_asy = true;
            case 3, base_name = 'zakharov';
            case 4, base_name = 'rosenbrock';
            case 5, base_name = 'rastrigin'; apply_osz = true; apply_asy = true;
            case 6, base_name = 'schafferf6'; apply_asy = true;
            case 7, base_name = 'lunacekbirastrigin';
            case 8, base_name = 'rastrigin_noncont'; apply_osz = true; apply_asy = true;
            case 9, base_name = 'levy'; apply_osz = true;
            case 10, base_name = 'schwefel'; apply_osz = true; apply_asy = true;
            otherwise, error('Invalid FID for Simple suite.');
        end

        fptr = cec2017.wrap_cec(base_name, n, shift_vec);
        comp.add(fptr, shift_vec, rotation, 1.0, 1.0, fid * 100.0, 1.0, [], apply_osz, apply_asy);
        scores = comp.evaluate(x);

    elseif fid <= 20
        % Hybrid Functions
        diff = x - repmat(shift_vec, m, 1);
        z = diff * rotation;

        current_shift = shift_vec;
        if ~isempty(permutation)
            z = z(:, permutation);
            current_shift = current_shift(permutation);
        end

        sizes = cec2017.get_partition_sizes(fid, n);
        switch fid
            case 11, base_fcns = {'zakharov', 'rosenbrock', 'rastrigin'};
            case 12, base_fcns = {'elliptic', 'schwefel', 'bentcigar'};
            case 13, base_fcns = {'bentcigar', 'rosenbrock', 'lunacekbirastrigin'};
            case 14, base_fcns = {'elliptic', 'ackley', 'schafferf7', 'rastrigin'};
            case 15, base_fcns = {'bentcigar', 'hgbat', 'rastrigin', 'rosenbrock'};
            case 16, base_fcns = {'schafferf6', 'hgbat', 'rosenbrock', 'schwefel'};
            case 17, base_fcns = {'katsuura', 'ackley', 'f8f2', 'schwefel', 'rastrigin'};
            case 18, base_fcns = {'elliptic', 'ackley', 'rastrigin', 'hgbat', 'discus'};
            case 19, base_fcns = {'bentcigar', 'rastrigin', 'f8f2', 'weierstrass', 'schafferf6'};
            case 20, base_fcns = {'hgbat', 'katsuura', 'ackley', 'rastrigin', 'schwefel', 'schafferf7'};
        end

        scores = zeros(m, 1);
        current_col = 1;
        for i = 1:length(base_fcns)
            sz = sizes(i);
            sub_z = z(:, current_col:current_col+sz-1);
            sub_o = current_shift(current_col:current_col+sz-1);
            fptr = cec2017.wrap_cec(base_fcns{i}, sz, sub_o);
            scores = scores + fptr(sub_z);
            current_col = current_col + sz;
        end
        scores = scores + fid * 100.0;

    else
        % Composition Functions
        comp = Composition(1.0);
        comp.UseSqrtWeight = true;

        switch fid
            case 21, cf_num = 3; base_fcns = {'rosenbrock', 'elliptic', 'rastrigin'}; sigmas = [10, 20, 30];
            case 22, cf_num = 3; base_fcns = {'rastrigin', 'griewank', 'schwefel'}; sigmas = [10, 20, 30];
            case 23, cf_num = 4; base_fcns = {'rosenbrock', 'ackley', 'schwefel', 'rastrigin'}; sigmas = [10, 20, 30, 40];
            case 24, cf_num = 4; base_fcns = {'ackley', 'elliptic', 'griewank', 'rastrigin'}; sigmas = [10, 20, 30, 40];
            case 25, cf_num = 5; base_fcns = {'rastrigin', 'happycat', 'ackley', 'discus', 'rosenbrock'}; sigmas = [10, 20, 30, 40, 50];
            case 26, cf_num = 5; base_fcns = {'schafferf6', 'schwefel', 'griewank', 'rosenbrock', 'rastrigin'}; sigmas = [10, 20, 30, 40, 50];
            case 27, cf_num = 6; base_fcns = {'hgbat', 'rastrigin', 'schwefel', 'bentcigar', 'elliptic', 'schafferf6'}; sigmas = [10, 10, 10, 20, 20, 20];
            case 28, cf_num = 10; base_fcns = {'ackley', 'griewank', 'discus', 'rosenbrock', 'happycat', 'schafferf6', 'schwefel', 'rastrigin', 'elliptic', 'bentcigar'}; sigmas = [10, 10, 20, 20, 30, 30, 40, 40, 50, 50];
            case 29, cf_num = 3; base_fcns = {'hybrid_f15', 'hybrid_f16', 'hybrid_f17'}; sigmas = [10, 30, 50];
            case 30, cf_num = 3; base_fcns = {'hybrid_f15', 'hybrid_f18', 'hybrid_f19'}; sigmas = [10, 30, 50];
        end

        for i = 1:cf_num
            sub_shift = shift_vec((i-1)*n + 1 : i*n);
            sub_rot = rotation((i-1)*n + 1 : i*n, :);

            if strncmp(base_fcns{i}, 'hybrid_', 7)
                h_fid = str2double(base_fcns{i}(9:end));
                fptr = @(v) evaluate_hybrid(v, h_fid);
            else
                fptr = cec2017.wrap_cec(base_fcns{i}, n, sub_shift);
            end

            comp.add(fptr, sub_shift, sub_rot, sigmas(i), 1.0, (i-1)*100.0, 1.0);
        end
        scores = comp.evaluate(x) + fid * 100.0;
    end
end

function h_res = evaluate_hybrid(v, h_fid)
    [mx, nx] = size(v);
    h_sizes = cec2017.get_partition_sizes(h_fid, nx);
    [h_shift_vec, ~, h_permutation] = cec2017.get_data(h_fid, nx);

    vz = v;
    vo = h_shift_vec;
    if ~isempty(h_permutation)
        vz = vz(:, h_permutation);
        vo = vo(h_permutation);
    end

    switch h_fid
        case 15, h_base_fcns = {'bentcigar', 'hgbat', 'rastrigin', 'rosenbrock'};
        case 16, h_base_fcns = {'schafferf6', 'hgbat', 'rosenbrock', 'schwefel'};
        case 17, h_base_fcns = {'katsuura', 'ackley', 'f8f2', 'schwefel', 'rastrigin'};
        case 18, h_base_fcns = {'elliptic', 'ackley', 'rastrigin', 'hgbat', 'discus'};
        case 19, h_base_fcns = {'bentcigar', 'rastrigin', 'f8f2', 'weierstrass', 'schafferf6'};
    end

    h_res = zeros(mx, 1);
    cur = 1;
    for k = 1:length(h_base_fcns)
        sz = h_sizes(k);
        sub_vz = vz(:, cur:cur+sz-1);
        sub_vo = vo(cur:cur+sz-1);
        fptr = cec2017.wrap_cec(h_base_fcns{k}, sz, sub_vo);
        h_res = h_res + fptr(sub_vz);
        cur = cur + sz;
    end
end
