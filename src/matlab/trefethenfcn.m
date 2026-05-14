% Computes the value of the Trefethen benchmark function.
% SCORES = TREFETHENFCN(X) computes the value of the function at point X.
% TREFETHENFCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = trefethenfcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Trefethen function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = exp(sin(50.0 * x1)) + sin(60.0 * exp(x2)) + sin(70.0 * sin(x1)) + ...
             sin(sin(80.0 * x2)) - sin(10.0 * (x1 + x2)) + 0.25 * (x1.^2 + x2.^2);
end
