% Computes the value of the DTLZ6 multi-objective benchmark function.
% SCORES = DTLZ6FCN(X, NUM_OBJECTIVES) computes the value of the DTLZ6 function
% at point X. DTLZ6FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-NUM_OBJECTIVES.
function scores = dtlz6fcn(x, num_objectives)
    n = size(x, 2);
    M = num_objectives;
    assert(n >= M, 'The DTLZ6 function requires n >= num_objectives.');

    k = n - M + 1;
    m = size(x, 1);
    scores = zeros(m, M);

    xm = x(:, n - k + 1:end);
    g = sum(xm.^0.1, 2);

    theta = zeros(m, M - 1);
    theta(:, 1) = x(:, 1) * (pi / 2.0);
    for j = 2:M - 1
        theta(:, j) = (pi ./ (4.0 * (1.0 + g))) .* (1.0 + 2.0 * g .* x(:, j));
    end

    for i = 1:M
        f_i = 1.0 + g;
        for j = 1:M - i
            f_i = f_i .* cos(theta(:, j));
        end
        if i > 1
            f_i = f_i .* sin(theta(:, M - i + 1));
        end
        scores(:, i) = f_i;
    end
end
