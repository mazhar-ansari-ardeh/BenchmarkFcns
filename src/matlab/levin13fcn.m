% Computes the value of the L�vi N. 13 benchmark function.
% SCORES = LEVIN13FCN(X) computes the value of the L�vi N. 13 function at
% point X. LEVIN13FCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/levin13fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = levin13fcn(x)
    n = size(x, 2);
    assert(n == 2, 'Levi''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);
    scores = sin(3 * pi * X) .^ 2 + ...
        ((X - 1).^2) .* (1 + sin(3 * pi * Y) .^ 2) + ...
        ((Y - 1).^2) .* (1 + sin(2 * pi * Y) .^ 2);
end
