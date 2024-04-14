% Computes the value of the Cross-in-tray benchmark function.
% SCORES = CROSSINTRAYFCN(X) computes the value of the Cross-in-tray
% function at point X. CROSSINTRAYFCN accepts a matrix of size M-by-2
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/crossintrayfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = crossintrayfcn(x)

    n = size(x, 2);
    assert(n == 2, 'The Cross-in-tray function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    expcomponent = abs(100 - (sqrt(X .^2 + Y .^2) / pi));

    scores = -0.0001 * ((abs(sin(X) .* sin(Y) .* exp(expcomponent)) + 1) .^ 0.1);
end
