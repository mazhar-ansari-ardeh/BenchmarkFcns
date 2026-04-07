% Computes the value of the ZDT4 multi-objective benchmark function.
% SCORES = ZDT4FCN(X) computes the value of the ZDT4 function
% at point X. ZDT4FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2 in which each row contains the function
% values for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/zdt4fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zdt4fcn(x)
    n = size(x, 2);
    assert(n >= 2, 'The ZDT4 function requires at least a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 2);
    scores(:, 1) = x(:, 1);
    g = 1.0 + 10.0 * (n - 1) + sum(x(:, 2:end).^2 - 10.0 * cos(4.0 * pi * x(:, 2:end)), 2);
    h = 1.0 - sqrt(scores(:, 1) ./ g);
    scores(:, 2) = g .* h;
end
