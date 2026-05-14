function scores = evaluate(x, fid)
    % EVALUATE Evaluates the CEC 2014 Single-Objective function.
    %   SCORES = EVALUATE(X, FID) evaluates function FID on input X.
    %   X: M-by-N matrix of points.
    %   FID: Function ID (1-30).

    [m, n] = size(x);

    % Get data
    [shift_vec, rotation, permutation] = cec2014.get_data(fid, n);

    if fid <= 16
        % Simple Functions
        comp = Composition(1.0);
        rotate = true;

        switch fid
            case 1, base_name = 'elliptic';
            case 2, base_name = 'bentcigar';
            case 3, base_name = 'discus';
            case 4, base_name = 'rosenbrock';
            case 5, base_name = 'ackley';
            case 6, base_name = 'weierstrass';
            case 7, base_name = 'griewank';
            case 8, base_name = 'rastrigin'; rotate = false;
            case 9, base_name = 'rastrigin';
            case 10, base_name = 'schwefel'; rotate = false;
            case 11, base_name = 'schwefel';
            case 12, base_name = 'katsuura';
            case 13, base_name = 'happycat';
            case 14, base_name = 'hgbat';
            case 15, base_name = 'f8f2';
            case 16, base_name = 'schafferf6';
            otherwise, error('Invalid FID for Simple suite.');
        end

        fptr = cec2014.wrap_cec(base_name, n, shift_vec);
        if rotate
            comp.add(fptr, shift_vec, rotation, 1.0, 1.0, fid * 100.0, 1.0);
        else
            comp.add(fptr, shift_vec, eye(n), 1.0, 1.0, fid * 100.0, 1.0);
        end
        scores = comp.evaluate(x);

    elseif fid <= 22
        % Hybrid Functions
        % CEC 2014 Hybrid: Shift -> Rotate -> Shuffle
        diff = x - repmat(shift_vec, m, 1);
        z = diff * rotation;

        current_shift = shift_vec;
        if ~isempty(permutation)
            z = z(:, permutation);
            current_shift = current_shift(permutation);
        end

        sizes = cec2014.get_partition_sizes(fid, n);
        switch fid
            case 17, base_fcns = {'rastrigin', 'rastrigin', 'elliptic'};
            case 18, base_fcns = {'bentcigar', 'katsuura', 'rastrigin'};
            case 19, base_fcns = {'griewank', 'weierstrass', 'rosenbrock', 'hgbat'};
            case 20, base_fcns = {'katsuura', 'discus', 'happycat', 'rastrigin'};
            case 21, base_fcns = {'hgbat', 'katsuura', 'rosenbrock', 'rastrigin', 'elliptic'};
            case 22, base_fcns = {'schwefel', 'schwefel', 'happycat', 'rastrigin', 'rosenbrock'};
        end

        scores = zeros(m, 1);
        current_col = 1;
        for i = 1:length(base_fcns)
            sz = sizes(i);
            sub_z = z(:, current_col:current_col+sz-1);
            sub_o = current_shift(current_col:current_col+sz-1);
            fptr = cec2014.wrap_cec(base_fcns{i}, sz, sub_o);
            scores = scores + fptr(sub_z);
            current_col = current_col + sz;
        end
        scores = scores + fid * 100.0;

    else
        % Composition Functions
        comp = Composition(1.0);
        comp.UseSqrtWeight = true;

        switch fid
            case 23, cf_num = 5; base_fcns = {'rosenbrock', 'elliptic', 'bentcigar', 'discus', 'elliptic'}; sigmas = [10, 20, 30, 40, 50]; lambdas = [1.0, 1e-6, 1e-26, 1e-6, 1e-6];
            case 24, cf_num = 3; base_fcns = {'schwefel', 'rastrigin', 'hgbat'}; sigmas = [20, 20, 20]; lambdas = [1, 1, 1];
            case 25, cf_num = 3; base_fcns = {'schwefel', 'rastrigin', 'elliptic'}; sigmas = [10, 30, 50]; lambdas = [0.25, 1.0, 1e-7];
            case 26, cf_num = 5; base_fcns = {'schwefel', 'happycat', 'elliptic', 'weierstrass', 'griewank'}; sigmas = [10, 10, 10, 10, 10]; lambdas = [0.25, 1.0, 1e-7, 2.5, 10.0];
            case 27, cf_num = 5; base_fcns = {'hgbat', 'rastrigin', 'schwefel', 'weierstrass', 'elliptic'}; sigmas = [10, 10, 10, 20, 20]; lambdas = [10, 10, 2.5, 25, 1e-6];
            case 28, cf_num = 5; base_fcns = {'f8f2', 'happycat', 'schwefel', 'schafferf6', 'elliptic'}; sigmas = [10, 20, 30, 40, 50]; lambdas = [2.5, 10, 2.5, 5e-4, 1e-6];
            case 29, cf_num = 3; base_fcns = {'hybrid_f17', 'hybrid_f18', 'hybrid_f19'}; sigmas = [10, 30, 50]; lambdas = [1, 1, 1];
            case 30, cf_num = 3; base_fcns = {'hybrid_f20', 'hybrid_f21', 'hybrid_f22'}; sigmas = [10, 30, 50]; lambdas = [1, 1, 1];
        end

        for i = 1:cf_num
            sub_shift = shift_vec((i-1)*100 + 1 : (i-1)*100 + n);
            sub_rot = rotation((i-1)*n + 1 : i*n, :);

            if strncmp(base_fcns{i}, 'hybrid_', 7)
                h_fid = str2double(base_fcns{i}(9:end));
                fptr = @(v) evaluate_hybrid(v, h_fid);
            else
                fptr = cec2014.wrap_cec(base_fcns{i}, n, sub_shift);
            end

            comp.add(fptr, sub_shift, sub_rot, sigmas(i), lambdas[i], (i-1)*100.0, 1.0);
        end
        scores = comp.evaluate(x) + fid * 100.0;
    end
end

function h_res = evaluate_hybrid(v, h_fid)
    [mx, nx] = size(v);
    h_sizes = cec2014.get_partition_sizes(h_fid, nx);
    [h_shift_vec, h_rot, h_permutation] = cec2014.get_data(h_fid, nx);

    % Shift is already handled by Composition
    vz = v * h_rot;
    vo = h_shift_vec;
    if ~isempty(h_permutation)
        vz = vz(:, h_permutation);
        vo = vo(h_permutation);
    end

    switch h_fid
        case 17, h_base_fcns = {'rastrigin', 'rastrigin', 'elliptic'};
        case 18, h_base_fcns = {'bentcigar', 'katsuura', 'rastrigin'};
        case 19, h_base_fcns = {'griewank', 'weierstrass', 'rosenbrock', 'hgbat'};
        case 20, h_base_fcns = {'katsuura', 'discus', 'happycat', 'rastrigin'};
        case 21, h_base_fcns = {'hgbat', 'katsuura', 'rosenbrock', 'rastrigin', 'elliptic'};
        case 22, h_base_fcns = {'schwefel', 'schwefel', 'happycat', 'rastrigin', 'rosenbrock'};
    end

    h_res = zeros(mx, 1);
    cur = 1;
    for k = 1:length(h_base_fcns)
        sz = h_sizes(k);
        sub_vz = vz(:, cur:cur+sz-1);
        sub_vo = vo(cur:cur+sz-1);
        fptr = cec2014.wrap_cec(h_base_fcns{k}, sz, sub_vo);
        h_res = h_res + fptr(sub_vz);
        cur = cur + sz;
    end
end
