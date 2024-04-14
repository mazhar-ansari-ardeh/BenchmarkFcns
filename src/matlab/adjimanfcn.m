% Computes the value of the Adjiman benchmark function.
% SCORES = ADJIMANHFCN(X) computes the value of the Adjiman function at
% point X. ADJIMANHFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/adjimanfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = adjimanfcn(x)

    n = size(x, 2);
    assert(n == 2, 'Adjiman function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (cos(X) .* sin(Y)) - (X ./ ((Y .^ 2) + 1));
end
