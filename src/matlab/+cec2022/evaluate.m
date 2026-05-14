function scores = evaluate(x, fid)
    % EVALUATE Evaluates the CEC 2022 Single-Objective function.

    [m, n] = size(x);

    % Get data
    [shift_vec, rotation, permutation] = cec2022.get_data(fid, n);

    if fid <= 5
        comp = Composition(1.0);
        sh_rate = 1.0;

        switch fid
            case 1, base_name = 'zakharov'; bias = 300.0;
            case 2, base_name = 'rosenbrock'; sh_rate = 0.02048; bias = 400.0;
            case 3, base_name = 'schafferf7'; bias = 600.0;
            case 4, base_name = 'rastrigin_noncont'; sh_rate = 0.0512; bias = 800.0;
            case 5, base_name = 'levy'; bias = 900.0;
        end

        fptr = cec2022.wrap_cec(base_name, n, shift_vec, sh_rate);
        comp.add(fptr, shift_vec, rotation, 1.0, 1.0, bias, 1.0);
        scores = comp.evaluate(x);

    elseif fid <= 8
        % Hybrid Functions
        diff = x - repmat(shift_vec, m, 1);
        z = diff * rotation;

        current_shift = shift_vec;
        if ~isempty(permutation)
            z = z(:, permutation);
            current_shift = current_shift(permutation);
        end

        if fid == 6
            p = [0.4, 0.4, 0.2];
            base_fcns = {'bentcigar', 'hgbat', 'rastrigin'};
            sh_rates = [1.0, 0.05, 0.0512];
            bias = 1800.0;
        elseif fid == 7
            p = [0.1, 0.2, 0.2, 0.2, 0.1, 0.2];
            base_fcns = {'hgbat', 'katsuura', 'ackley', 'rastrigin', 'schwefel', 'schafferf7'};
            sh_rates = [0.05, 0.05, 1.0, 0.0512, 10.0, 1.0];
            bias = 2000.0;
        else
            p = [0.3, 0.2, 0.2, 0.1, 0.2];
            base_fcns = {'katsuura', 'happycat', 'f8f2', 'schwefel', 'ackley'};
            sh_rates = [0.05, 0.05, 0.05, 10.0, 1.0];
            bias = 2200.0;
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
            fptr = cec2022.wrap_cec(base_fcns{i}, sz, sub_o, sh_rates(i));
            scores = scores + fptr(sub_z);
            current_col = current_col + sz;
        end
        scores = scores + bias;

    else
        % Composition Functions
        comp = Composition(1.0);
        comp.UseSqrtWeight = true;

        if fid == 9
            cf_num = 5; base_fcns = {'rosenbrock', 'elliptic', 'bentcigar', 'discus', 'elliptic'}; sigmas = [10, 20, 30, 40, 50]; sh_rates = [0.02048, 1.0, 1.0, 1.0, 1.0]; biases = [0, 200, 300, 100, 400]; final_bias = 2300.0;
        elseif fid == 10
            cf_num = 3; base_fcns = {'schwefel', 'rastrigin', 'hgbat'}; sigmas = [20, 10, 10]; sh_rates = [10.0, 0.0512, 0.05]; biases = [0, 200, 100]; final_bias = 2400.0;
        elseif fid == 11
            cf_num = 5; base_fcns = {'schafferf6', 'schwefel', 'griewank', 'rosenbrock', 'rastrigin'}; sigmas = [20, 20, 30, 30, 20]; sh_rates = [1.0, 10.0, 6.0, 0.02048, 0.0512]; biases = [0, 200, 300, 400, 200]; final_bias = 2600.0;
        else
            cf_num = 6; base_fcns = {'hgbat', 'rastrigin', 'schwefel', 'bentcigar', 'elliptic', 'schafferf6'}; sigmas = [10, 20, 30, 40, 50, 60]; sh_rates = [0.05, 0.0512, 10.0, 1.0, 1.0, 1.0]; biases = [0, 300, 500, 100, 400, 200]; final_bias = 2700.0;
        end

        for i = 1:cf_num
            sub_shift = shift_vec((i-1)*100 + 1 : (i-1)*100 + n);
            sub_rot = rotation((i-1)*n + 1 : i*n, :);
            fptr = cec2022.wrap_cec(base_fcns{i}, n, sub_shift, sh_rates(i));
            comp.add(fptr, sub_shift, sub_rot, sigmas(i), 1.0, biases(i), 1.0);
        end
        scores = comp.evaluate(x) + final_bias;
    end
end
