% Computes the value of the Ursem N. 4 benchmark function.
% SCORES = URSEMN4FCN(X) computes the value of the function at point X.
% URSEMN4FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = ursemn4fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Ursem N. 4 function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = -3.0 * sin(0.5 * pi * x1 + 0.5 * pi) .* (2.0 - sqrt(x1.^2 + x2.^2)) / 2.0;
end
