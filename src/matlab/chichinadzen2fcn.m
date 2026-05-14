% Computes the value of the Chichinadze N. 2 benchmark function.
% SCORES = CHICHINADZEN2FCN(X) computes the value of the function at point X.
% CHICHINADZEN2FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = chichinadzen2fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Chichinadze N. 2 function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = x1.^2 - 12.0 * x1 + 11.0 + 10.0 * cos(0.5 * pi * x1) + ...
             8.0 * sin(5.0 * pi * x1) - 0.2 * sqrt(5.0) * exp(-0.5 * (x2 - 0.5).^2);
end
