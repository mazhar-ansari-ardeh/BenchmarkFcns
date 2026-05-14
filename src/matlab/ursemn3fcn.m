% Computes the value of the Ursem N. 3 benchmark function.
% SCORES = URSEMN3FCN(X) computes the value of the function at point X.
% URSEMN3FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = ursemn3fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Ursem N. 3 function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    term1 = -sin(2.2 * pi * x1 + 0.5 * pi) .* (3.0 - abs(x1)) / 2.0 .* (2.0 - abs(x2)) / 2.0;
    term2 = -sin(0.5 * pi * x2.^2 + 0.5 * pi) .* (2.0 - abs(x1)) / 2.0 .* (2.0 - abs(x2)) / 2.0;

    scores = term1 + term2;
end
