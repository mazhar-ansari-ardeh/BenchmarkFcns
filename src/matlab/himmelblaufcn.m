% Computes the value of the Himmelblau's benchmark function.
% SCORES = HIMMELBLAUFCN(X) computes the value of the Himmelblau's
% function at point X. HIMMELBLAUFCN accepts a matrix of size M-by-2
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/himmelblaufcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = himmelblaufcn(x)
    n = size(x, 2);
    assert(n == 2, 'Himmelblau''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = ((X .^ 2 + Y - 11) .^2) + ((X + (Y .^ 2) - 7) .^ 2);
end
