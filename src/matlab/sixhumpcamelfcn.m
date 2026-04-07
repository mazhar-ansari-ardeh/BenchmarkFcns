% Computes the value of the Six-hump camel benchmark function.
% SCORES = SIXHUMPCAMELFCN(X) computes the value of the Six-hump camel
% function at point X. SIXHUMPCAMELFCN accepts a matrix of size M-by-2
% and returns a vector SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/sixhumpcamelfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = sixhumpcamelfcn(x)

    n = size(x, 2);
    assert(n == 2, 'The Six-hump camel function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (4 - 2.1 * X .^ 2 + (X .^ 4) / 3) .* (X .^ 2) + X .* Y + (-4 + 4 * Y .^ 2) .* (Y .^ 2);
end
