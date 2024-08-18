% Computes the value of the Bukin N02 function.
% SCORES = BUKINN2FCN(X) computes the value of the Xin-She Yang
% function at point X. BUKINN2FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bukinn2fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Bukin N02 function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = 100 * (Y .^ 2 - 0.01 * X .^ 2 + 1) + 0.01 * ((X + 10) .^ 2);
end
