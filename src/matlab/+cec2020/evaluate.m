function scores = evaluate(x, fid)
    % EVALUATE Evaluates the CEC 2020 Single-Objective function.

    [m, n] = size(x);

    % Get data
    [shift_vec, rotation, permutation] = cec2020.get_data(fid, n);

    if fid <= 4
        comp = Composition(1.0);
        sh_rate = 1.0;

        switch fid
            case 1, base_name = 'bentcigar';
            case 2, base_name = 'schwefel'; sh_rate = 10.0;
            case 3, base_name = 'lunacekbirastrigin'; sh_rate = 0.1;
            case 4, base_name = 'f8f2'; sh_rate = 0.05;
        end

        fptr = cec2020.wrap_cec(base_name, n, shift_vec, sh_rate);
        comp.add(fptr, shift_vec, rotation, 1.0, 1.0, fid * 100.0, 1.0);

        % Biases for 2020: 100, 700, 800, 900
        if fid == 1
            bias = 100.0;
        else
            bias = 600.0 + fid * 100.0;
        end
        scores = comp.evaluate(x) - fid * 100.0 + bias;

    elseif fid <= 7
        % Hybrid Functions
        diff = x - repmat(shift_vec, m, 1);
        z = diff * rotation;

        current_shift = shift_vec;
        if ~isempty(permutation)
            z = z(:, permutation);
            current_shift = current_shift(permutation);
        end

        if fid == 5
            p = [0.3, 0.3, 0.4];
            base_fcns = {'schwefel', 'rastrigin', 'elliptic'};
            sh_rates = [10.0, 0.0512, 1.0];
            bias = 1600.0;
        elseif fid == 6
            p = [0.25, 0.25, 0.25, 0.25];
            base_fcns = {'schafferf6', 'hgbat', 'rosenbrock', 'schwefel'};
            sh_rates = [1.0, 0.05, 0.02048, 10.0];
            bias = 1700.0;
        else
            p = [0.2, 0.2, 0.2, 0.2, 0.2];
            base_fcns = {'schafferf6', 'hgbat', 'rosenbrock', 'schwefel', 'elliptic'};
            sh_rates = [1.0, 0.05, 0.02048, 10.0, 1.0];
            bias = 1800.0;
        end

        sizes = zeros(1, length(p));
        current_sum = 0;
        for i = 1:length(p)-1
            sz = ceil(p(i) * n);
            sizes(i) = sz;
            current_sum = current_sum + sz;
        end
        sizes(end) = n - current_sum;

        scores = zeros(m, 1);
        current_col = 1;
        for i = 1:length(base_fcns)
            sz = sizes(i);
            sub_z = z(:, current_col:current_col+sz-1);
            sub_o = current_shift(current_col:current_col+sz-1);
            fptr = cec2020.wrap_cec(base_fcns{i}, sz, sub_o, sh_rates(i));
            scores = scores + fptr(sub_z);
            current_col = current_col + sz;
        end
        scores = scores + bias;

    else
        % Composition Functions
        comp = Composition(1.0);
        comp.UseSqrtWeight = true;

        if fid == 8
            cf_num = 3; base_fcns = {'rosenbrock', 'elliptic', 'rastrigin'}; sigmas = [10, 20, 30]; sh_rates = [0.02048, 1.0, 0.0512]; bias = 2200.0;
        elseif fid == 9
            cf_num = 4; base_fcns = {'ackley', 'elliptic', 'griewank', 'rastrigin'}; sigmas = [10, 20, 30, 40]; sh_rates = [1.0, 1.0, 6.0, 0.0512]; bias = 2300.0;
        else
            cf_num = 5; base_fcns = {'rastrigin', 'happycat', 'ackley', 'discus', 'rosenbrock'}; sigmas = [10, 20, 30, 40, 50]; sh_rates = [0.0512, 0.05, 1.0, 1.0, 0.02048]; bias = 2400.0;
        end

        for i = 1:cf_num
            sub_shift = shift_vec((i-1)*100 + 1 : (i-1)*100 + n);
            sub_rot = rotation((i-1)*n + 1 : i*n, :);
            fptr = cec2020.wrap_cec(base_fcns{i}, n, sub_shift, sh_rates(i));
            comp.add(fptr, sub_shift, sub_rot, sigmas(i), 1.0, (i-1)*100.0, 1.0);
        end
        scores = comp.evaluate(x) + bias;
    end
end
