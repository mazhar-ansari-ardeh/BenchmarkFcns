% Computes the value of Bohachevsky N. 1 benchmark function.
% SCORES = BOHACHEVSKYN1FCN(X) computes the value of the Bohachevsky N. 1
% function at point X. BOHACHEVSKYFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for each row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/bohachevskyn1fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bohachevskyn1fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Bohachevsky N. 1 function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (X .^ 2) + (2 * Y .^ 2) - (0.3 * cos(3 * pi * X)) - (0.4 * cos(4 * pi * Y)) + 0.7;
end
