% Computes the value of the ZDT2 multi-objective benchmark function.
% SCORES = ZDT2FCN(X) computes the value of the ZDT2 function
% at point X. ZDT2FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2 in which each row contains the function
% values for the corresponding row of X.
function scores = zdt2fcn(x)
    n = size(x, 2);
    assert(n >= 2, 'The ZDT2 function requires at least a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 2);
    scores(:, 1) = x(:, 1);
    g = 1.0 + (9.0 / (n - 1)) * sum(x(:, 2:end), 2);
    h = 1.0 - (scores(:, 1) ./ g).^2;
    scores(:, 2) = g .* h;
end
