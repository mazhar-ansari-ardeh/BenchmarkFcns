% Computes the value of the Picheny benchmark function.
% SCORES = PICHENYFCN(X) computes the value of the Beale function at
% point X. PICHENYFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/pichenyfcn
%
% Note: The Picheny function is a modification of the Goldstein-Price
% function.
% See also: goldsteinpricefcn.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = pichenyfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Picheny function is only defined on a 2D space.')
    X = 4 * x(:, 1) - 2;
    Y = 4 * x(:, 2) - 2;

    term = (1 + ((X + Y + 1).^2) * (19 - (14 * X) + (3 * (X .^2)) - 14*Y + (6 .* X.*Y) + (3 * (Y.^2)))) .* ...
        (30 + ((2 * X - 3 * Y).^2) .* (18 - 32 * X + 12 * (X .^2) + 48 * Y - (36 .* X.*Y) + (27 * (Y.^2))) );
    coef = 1 / 2.427;
    scores = coef * (log10(term) - 8.693);
end
