function comp = cec2005_f15(n)
    % CEC2005_F15 Returns a Composition object for CEC 2005 F15.

    comp = Composition();

    % 10 base functions
    % Using strings for compatibility with the existing .m files
    functions = {'rastrigin', 'rastrigin', 'weierstrass', 'weierstrass', ...
                 'griewank', 'griewank', 'ackley', 'ackley', 'sphere', 'sphere'};

    % Standard parameters for F15
    sigmas = ones(1, 10);
    biases = 0:100:900;
    f_maxs = ones(1, 10) * 10; % Placeholder estimates

    % Generate shifted centers (Deterministic for parity with Python example)
    rng(42);

    for i = 1:10
        shift = (rand(1, n) * 10) - 5;
        comp.add(functions{i}, shift, [], sigmas(i), 1.0, biases(i), f_maxs(i));
    end
end
