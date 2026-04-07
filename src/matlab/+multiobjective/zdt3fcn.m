% Computes the value of the ZDT3 multi-objective benchmark function.
% SCORES = ZDT3FCN(X) computes the value of the ZDT3 function
% at point X. ZDT3FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2 in which each row contains the function
% values for the corresponding row of X.
function scores = zdt3fcn(x)
    n = size(x, 2);
    assert(n >= 2, 'The ZDT3 function requires at least a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 2);
    scores(:, 1) = x(:, 1);
    g = 1.0 + (9.0 / (n - 1)) * sum(x(:, 2:end), 2);
    f1_g = scores(:, 1) ./ g;
    h = 1.0 - sqrt(f1_g) - f1_g .* sin(10.0 * pi * scores(:, 1));
    scores(:, 2) = g .* h;
end
