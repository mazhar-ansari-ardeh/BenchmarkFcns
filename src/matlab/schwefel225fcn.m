% Computes the value of the Schwefel 2.25 benchmark function.
% SCORES = SCHWEFEL225FCN(X) computes the value of the Schwefel 2.25 function at point X.
% SCHWEFEL225FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = schwefel225fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    scores = zeros(m, 1);
    for i = 2:n
        xi = x(:, i);
        scores = scores + (xi - 1.0).^2 + (x1 - xi.^2).^2;
    end
end
