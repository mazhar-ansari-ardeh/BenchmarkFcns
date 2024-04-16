% Computes the value of Goldstein-Price benchmark function.
% SCORES = GOLDSTEINPRICEFCN(X) computes the value of the Goldstein-Price
% function at point X. GOLDSTEINPRICEFCN accepts a matrix of size M-by-2
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/goldsteinpricefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = goldsteinpricefcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Goldstein-Price function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (1 + ((X + Y + 1).^2) * (19 - (14 * X) + (3 * (X .^2)) - 14*Y + (6 .* X.*Y) + (3 * (Y.^2)))) .* ...
        (30 + ((2 * X - 3 * Y).^2) .* (18 - 32 * X + 12 * (X .^2) + 48 * Y - (36 .* X.*Y) + (27 * (Y.^2))) );
end
