% Computes the value of the DTLZ7 multi-objective benchmark function.
% SCORES = DTLZ7FCN(X, NUM_OBJECTIVES) computes the value of the DTLZ7
% function at point X. DTLZ7FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-K where K is the number of objectives.
% For more information, please visit:
% benchmarkfcns.info/doc/dtlz7fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = dtlz7fcn(x, num_objectives)
    if nargin < 2
        num_objectives = 3;
    end

    [m, n] = size(x);
    M = num_objectives;
    assert(n >= M, 'The DTLZ7 function requires n >= num_objectives.');

    k = n - M + 1;
    xm = x(:, n-k+1:end);

    scores = zeros(m, M);
    for i = 1:M-1
        scores(:, i) = x(:, i);
    end

    g = 1 + (9/k) * sum(xm, 2);

    h = M;
    for i = 1:M-1
        h = h - (scores(:, i) ./ (1 + g)) .* (1 + sin(3 * pi * scores(:, i)));
    end

    scores(:, M) = (1 + g) .* h;
end
