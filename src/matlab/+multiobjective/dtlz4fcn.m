% Computes the value of the DTLZ4 multi-objective benchmark function.
% SCORES = DTLZ4FCN(X, NUM_OBJECTIVES, ALPHA) computes the value of the DTLZ4 function
% at point X. DTLZ4FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-NUM_OBJECTIVES.
function scores = dtlz4fcn(x, num_objectives, alpha)
    if nargin < 3
        alpha = 100.0;
    end
    n = size(x, 2);
    M = num_objectives;
    assert(n >= M, 'The DTLZ4 function requires n >= num_objectives.');

    k = n - M + 1;
    m = size(x, 1);
    scores = zeros(m, M);

    xm = x(:, n - k + 1:end);
    g = sum((xm - 0.5).^2, 2);

    for i = 1:M
        f_i = 1.0 + g;
        for j = 1:M - i
            f_i = f_i .* cos(x(:, j).^alpha * (pi / 2.0));
        end
        if i > 1
            f_i = f_i .* sin(x(:, M - i + 1).^alpha * (pi / 2.0));
        end
        scores(:, i) = f_i;
    end
end
