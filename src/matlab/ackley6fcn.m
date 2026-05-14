% Computes the value of the Ackley N. 6 benchmark function.
% SCORES = ACKLEY6FCN(X) computes the value of the function at point X.
% ACKLEY6FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = ackley6fcn(x)
    [m, n] = size(x);
    scores = ones(m, 1);
    for i = 1:(n-1)
        xi = x(:, i);
        xi_plus_1 = x(:, i+1);
        scores = scores + (1.0 - cos(2.0 * pi * sqrt(xi.^2 + xi_plus_1.^2)));
    end
end
