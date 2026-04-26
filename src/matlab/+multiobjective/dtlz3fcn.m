% Computes the value of the DTLZ3 multi-objective benchmark function.
% SCORES = DTLZ3FCN(X, NUM_OBJECTIVES) computes the value of the DTLZ3
% function at point X. DTLZ3FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-K where K is the number of objectives.
% For more information, please visit:
% benchmarkfcns.info/doc/dtlz3fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = dtlz3fcn(x, num_objectives)
    if nargin < 2
        num_objectives = 3;
    end

    [m, n] = size(x);
    M = num_objectives;
    assert(n >= M, 'The DTLZ3 function requires n >= num_objectives.');

    k = n - M + 1;
    xm = x(:, n-k+1:end);

    g = 100 * (k + sum((xm - 0.5).^2 - cos(20 * pi * (xm - 0.5)), 2));

    scores = zeros(m, M);
    for i = 1:M
        f_i = (1 + g);
        for j = 1:M-i
            f_i = f_i .* cos(x(:, j) * pi / 2);
        end
        if i > 1
            f_i = f_i .* sin(x(:, M-i+1) * pi / 2);
        end
        scores(:, i) = f_i;
    end
end
