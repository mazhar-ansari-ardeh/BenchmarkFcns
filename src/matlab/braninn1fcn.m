% Computes the value of the Branin N01 benchmark function.
% SCORES = BRANINN1FCN(X) computes the value of the Branin N01
% function at point X. BRANINN1FCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/braninn1fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = braninn1fcn(x)

    n = size(x, 2);
    assert(n == 2, 'Branin N01 function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (-1.275 * X.^2/(pi^2) + 5 * X/pi + Y - 6).^2 + (10 - 5/(4*pi)) * cos(X) + 10;
end
