% Computes the value of the Trigonometric N. 1 benchmark function.
% SCORES = TRIGONOMETRICN1FCN(X) computes the value of the function at point X.
% TRIGONOMETRICN1FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = trigonometricn1fcn(x)
    [m, n] = size(x);
    sum_cos = sum(cos(x), 2);
    scores = zeros(m, 1);
    for i = 1:n
        scores = scores + (n - sum_cos + i * (1.0 - cos(x(:, i)) - sin(x(:, i)))).^2;
    end
end
