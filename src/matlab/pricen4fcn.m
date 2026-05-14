% Computes the value of the Price N. 4 benchmark function.
% SCORES = PRICEN4FCN(X) computes the value of the Price N. 4 function at point X.
% PRICEN4FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = pricen4fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Price N. 4 function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = (2.0 * x1.^3 .* x2 - x2.^3).^2 + (6.0 * x1 - x2.^2 + x2).^2;
end
