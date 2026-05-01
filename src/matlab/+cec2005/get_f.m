function comp = get_f(f_id, n)
    % GET_F Returns a Composition object for a CEC 2005 benchmark function.
    % f_id: Function ID (1 to 25)
    % n: Number of dimensions

    comp = Composition();

    % Reproducible shift/rotation data generator
    rng(f_id * 1000 + n);

    function [shifts, rotations] = get_data(num_comp)
        shifts = cell(1, num_comp);
        rotations = cell(1, num_comp);
        for i = 1:num_comp
            shifts{i} = (rand(1, n) * 100) - 50;
            rotations{i} = eye(n);
        end
    end

    switch f_id
        case 1
            [s, r] = get_data(1);
            comp.add('sphere', s{1}, r{1}, 1.0, 1.0, -450.0);
        case 2
            [s, r] = get_data(1);
            comp.add('schwefel12', s{1}, r{1}, 1.0, 1.0, -450.0);
        case 3
            [s, r] = get_data(1);
            comp.add('elliptic', s{1}, r{1}, 1.0, 1.0, -450.0);
        case 4
            [s, r] = get_data(1);
            comp.add('schwefel12', s{1}, r{1}, 1.0, 1.0, -450.0);
        case 5
            [s, r] = get_data(1);
            comp.add('schwefel', s{1}, r{1}, 1.0, 1.0, -310.0);
        case 6
            [s, r] = get_data(1);
            comp.add('rosenbrock', s{1}, r{1}, 1.0, 1.0, 390.0);
        case 7
            [s, r] = get_data(1);
            comp.add('griewank', s{1}, r{1}, 1.0, 1.0, -180.0);
        case 8
            [s, r] = get_data(1);
            comp.add('ackley', s{1}, r{1}, 1.0, 1.0, -140.0);
        case 9
            [s, r] = get_data(1);
            comp.add('rastrigin', s{1}, r{1}, 1.0, 1.0, -330.0);
        case 10
            [s, r] = get_data(1);
            comp.add('rastrigin', s{1}, r{1}, 1.0, 1.0, -330.0);
        case 11
            [s, r] = get_data(1);
            comp.add('weierstrass', s{1}, r{1}, 1.0, 1.0, 90.0);
        case 12
            [s, r] = get_data(1);
            comp.add('schwefel', s{1}, r{1}, 1.0, 1.0, -460.0);
        case 13
            [s, r] = get_data(1);
            comp.add('f8f2', s{1}, r{1}, 1.0, 1.0, -130.0);
        case 14
            [s, r] = get_data(1);
            comp.add('schafferf6', s{1}, r{1}, 1.0, 1.0, -300.0);
        case {15, 18, 21, 24}
            % Generic Hybrid Composition Factory
            if f_id == 15
                base = {'rastrigin', 'rastrigin', 'weierstrass', 'weierstrass', 'griewank', 'griewank', 'ackley', 'ackley', 'sphere', 'sphere'};
                sigmas = ones(1, 10);
                bias_val = 120;
            elseif f_id == 18
                base = {'rastrigin', 'rastrigin', 'weierstrass', 'weierstrass', 'griewank', 'griewank', 'ackley', 'ackley', 'sphere', 'sphere'};
                sigmas = [1.0, 2.0, 1.5, 1.5, 1.0, 1.0, 2.0, 2.0, 1.5, 1.5];
                bias_val = 10;
            elseif f_id == 21
                base = {'f8f2', 'f8f2', 'weierstrass', 'weierstrass', 'griewank', 'griewank', 'ackley', 'ackley', 'sphere', 'sphere'};
                sigmas = [1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0];
                bias_val = 360;
            else % 24
                base = {'weierstrass', 'weierstrass', 'rastrigin', 'rastrigin', 'griewank', 'griewank', 'ackley', 'ackley', 'sphere', 'sphere'};
                sigmas = [1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0];
                bias_val = 260;
            end

            [s, r] = get_data(10);
            biases = (0:9) * 100;
            for i = 1:10
                comp.add(base{i}, s{i}, r{i}, sigmas(i), 1.0, biases(i), 10.0);
            end
        otherwise
            error('CEC 2005 Function ID %d not yet explicitly implemented or invalid.', f_id);
    end
end
