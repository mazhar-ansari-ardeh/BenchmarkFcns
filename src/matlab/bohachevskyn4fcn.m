% Computes the value of the Bohachevsky N. 4 benchmark function.
% SCORES = BOHACHEVSKYN4FCN(X) computes the value of the function at point X.
% BOHACHEVSKYN4FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = bohachevskyn4fcn(x)
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:(n-1)
        xi = x(:, i);
        xi_plus_1 = x(:, i+1);
        scores = scores + xi.^2 + 2.0 * xi_plus_1.^2 - 0.3 * cos(3.0 * pi * xi) - ...
                 0.4 * cos(4.0 * pi * xi_plus_1) + 0.7;
    end
end
