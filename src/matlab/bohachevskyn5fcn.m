% Computes the value of the Bohachevsky N. 5 benchmark function.
% SCORES = BOHACHEVSKYN5FCN(X) computes the value of the function at point X.
% BOHACHEVSKYN5FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = bohachevskyn5fcn(x)
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:(n-1)
        xi = x(:, i);
        xi_plus_1 = x(:, i+1);
        scores = scores + xi.^2 + 2.0 * xi_plus_1.^2 - 0.3 * cos(3.0 * pi * xi) .* ...
                 cos(4.0 * pi * xi_plus_1) + 0.3;
    end
end
