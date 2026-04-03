% Computes the value of the Schaffer F6 function.
% SCORES = SCHAFFERF6FCN(X) computes the value of the Schaffer F6
% function at point X. SCHAFFERF6FCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/schafferf6fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = schafferf6fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Schaffer F6 function is only defined on a 2D space.');

    X2 = x(:, 1).^2;
    Y2 = x(:, 2).^2;
    x2y2 = X2 + Y2;

    numerator = (sin(sqrt(x2y2))).^2 - 0.5;
    denominator = (1.0 + 0.001 * x2y2).^2;
    scores = 0.5 + numerator ./ denominator;
end
