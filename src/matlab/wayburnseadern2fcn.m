% Computes the value of the Wayburn-Seader N. 02 function.
% SCORES = WAYBURNSEADERN2FCN(X) computes the value of the Wayburn-Seader N. 02
% function at point X. WAYBURNSEADERN2FCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = wayburnseadern2fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Wayburn-Seader N. 02 function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (1.613 - 4 * (X - 0.3125) .^ 2 - 4 * (Y - 1.625) .^ 2) .^ 2 + (Y - 1) .^ 2;
end
