% Computes the value of the DTLZ2 multi-objective benchmark function.
% SCORES = DTLZ2FCN(X, NUM_OBJECTIVES) computes the value of the DTLZ2 function
% at point X. DTLZ2FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-NUM_OBJECTIVES in which each row contains
% the function values for the corresponding row of X.
function scores = dtlz2fcn(x, num_objectives)
    if nargin < 2
        num_objectives = 3;
    end
    n = size(x, 2);
    M = num_objectives;
    assert(n >= M, 'The DTLZ2 function requires n >= num_objectives.');
    m = size(x, 1);
    k = n - M + 1;

    xm = x(:, end-k+1:end);
    g = sum((xm - 0.5).^2, 2);

    scores = zeros(m, M);
    for i = 1:M
        f_i = 1 + g;
        for j = 1:(M - i)
            f_i = f_i .* cos(x(:, j) * pi / 2);
        end
        if i > 1
            f_i = f_i .* sin(x(:, M - i + 1) * pi / 2);
        end
        scores(:, i) = f_i;
    end
end
