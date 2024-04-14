% Computes the value of the Easom benchmark function.
% SCORES = EASOMFCN(X) computes the value of the Easom function at point X.
% EASOMFCN accepts a matrix of size M-by-2 and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/easomfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = easomfcn(x)

    n = size(x, 2);
    assert(n == 2, 'The Easom''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = -cos(X) .* cos(Y) .* exp(-( ((X - pi) .^2) + ((Y - pi) .^ 2)) );
end
