% Computes the value of the Wayburn-Seader N. 1 benchmark function.
% SCORES = WAYBURNSEADERN1FCN(X) computes the value of the function at point X.
% WAYBURNSEADERN1FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = wayburnseadern1fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Wayburn-Seader N. 1 function is only defined on a 2D space.');
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores = (x1.^6 + x2.^4 - 17.0).^2 + (2.0 * x1 + x2 - 4.0).^2;
end
