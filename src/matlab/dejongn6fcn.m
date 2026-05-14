% Computes the value of the De Jong N. 6 (Wood) benchmark function.
% SCORES = DEJONGN6FCN(X) computes the value of the function at point X.
% DEJONGN6FCN accepts a matrix of size M-by-4 and returns a vector SCORES of size M-by-1.
function scores = dejongn6fcn(x)
    [m, n] = size(x);
    assert(n == 4, 'The De Jong N. 6 (Wood) function is only defined on a 4D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    scores = 100.0 * (x1.^2 - x2).^2 + (x1 - 1.0).^2 + (x3 - 1.0).^2 + ...
             90.0 * (x3.^2 - x4).^2 + 10.1 * ((x2 - 1.0).^2 + (x4 - 1.0).^2) + ...
             19.8 * (x2 - 1.0) .* (x4 - 1.0);
end
