% Computes the value of the Leon function.
% SCORES = LEONFCN(X) computes the value of the Leon function at point X.
% LEONFCN accepts a matrix of size M-by-2 and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/leonfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = leonfcn(x)
    n = size(x, 2);
    assert(n == 2, 'Leon function is defined only on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = 100 * ((Y - X.^3) .^2) + ((1 - X) .^2);
end
