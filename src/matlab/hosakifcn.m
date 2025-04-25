% Computes the value of the Adjiman benchmark function.
% SCORES = HOSAKIFCN(X) computes the value of the Adjiman function at
% point X. HOSAKIFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = hosakifcn(x)

    n = size(x, 2);
    assert(n == 2, 'Adjiman function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (1 - 8 * X + 7 * X .^ 2 - (7/3) * X .^ 3 + 0.25 * X .^ 4) .* (Y .^2) .* exp(-X)
end
