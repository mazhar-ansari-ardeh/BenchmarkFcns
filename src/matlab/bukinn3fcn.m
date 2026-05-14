% Computes the value of the Bukin N. 3 benchmark function.
% SCORES = BUKINN3FCN(X) computes the value of the function at point X.
% BUKINN3FCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = bukinn3fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Bukin N. 3 function is only defined on a 2D space.');
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores = 100.0 * abs(x2 - 0.01 * x1.^2) + 0.01 * abs(x1 + 10.0);
end
