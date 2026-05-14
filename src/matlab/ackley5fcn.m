% Computes the value of the Ackley N. 5 benchmark function.
% SCORES = ACKLEY5FCN(X) computes the value of the function at point X.
% ACKLEY5FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = ackley5fcn(x)
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:(n-1)
        xi = x(:, i);
        xi_plus_1 = x(:, i+1);
        scores = scores + 20.0 + exp(1) - 20.0 * exp(-0.2 * sqrt(xi.^2 + xi_plus_1.^2)) - ...
                 exp(0.5 * (cos(2.0 * pi * xi) + cos(2.0 * pi * xi_plus_1)));
    end
end
