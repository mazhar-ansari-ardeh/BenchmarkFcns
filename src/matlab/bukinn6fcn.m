% Computes the value of the Bukin N. 6 benchmark function.
% SCORES = BUKINN6FCN(X) computes the value of the Bukin N. 6 function at
% point X. BUKINN6FCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/bukinn6fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bukinn6fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Bukin N. 6 functions is only defined on a 2D space.')

    X = x(:, 1);
    X2 = X .^ 2;
    Y = x(:, 2);

    scores = 100 * sqrt(abs(Y - 0.01 * X2)) + 0.01 * abs(X  + 10);
end
