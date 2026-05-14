% Computes the value of the Price N. 3 (Modified Rosenbrock) benchmark function.
% SCORES = PRICEN3FCN(X) computes the value of the Price N. 3 function at point X.
% PRICEN3FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = pricen3fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Price N. 3 function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = 100.0 * (x2 - x1.^2).^2 + (1.0 - x1).^2 + 6.4 * cos(x1 - 1.0) - 6.4;
end
