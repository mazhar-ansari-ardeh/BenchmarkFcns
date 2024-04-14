% Computes the value of the Matyas benchmark function.
% SCORES = MATYASFCN(X) computes the value of the Matyas function at
% point X. MATYASFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/matyasfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = matyasfcn(x)
    n = size(x, 2);
    assert(n == 2, 'Matyas''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = 0.26 * (X .^ 2 + Y.^2) - 0.48 * X .* Y;
end
