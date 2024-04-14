% Computes the value of the Ackley N. 3 function.
% SCORES = ACKLEYN3FCN(X) computes the value of the Ackley N. 3
% function at point X. ACKLEYN3FCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/ackleyn3fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = ackleyn3fcn(x)

    n = size(x, 2);
    assert(n == 2, 'Ackley N. 3 function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = -200 * exp(-0.2 * sqrt((X .^ 2) + (Y .^ 2))) + ...
             5 * exp(cos(3 * X) + sin(3 * Y));
end
