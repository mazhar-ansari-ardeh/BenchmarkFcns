% Computes the value of the Wayburn-Seader N. 3 benchmark function.
% SCORES = WAYBURNSEADERN3FCN(X) computes the value of the function at point X.
% WAYBURNSEADERN3FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = wayburnseadern3fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Wayburn-Seader N. 3 function is only defined on a 2D space.');
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores = 2.0 / 3.0 * x1.^3 - 8.0 * x1.^2 + 33.0 * x1 - x1 .* x2 + 5.0 + ...
             ((x1 - 4.0).^2 + (x2 - 5.0).^2 - 4.0).^2;
end
