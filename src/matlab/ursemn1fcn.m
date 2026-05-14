% Computes the value of the Ursem N. 1 benchmark function.
% SCORES = URSEMN1FCN(X) computes the value of the function at point X.
% URSEMN1FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = ursemn1fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Ursem N. 1 function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = -sin(2.0 * x1 - 0.5 * pi) - 3.0 * cos(x2) - 0.5 * x1;
end
