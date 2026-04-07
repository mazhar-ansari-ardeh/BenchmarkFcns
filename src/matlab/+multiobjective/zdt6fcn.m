% Computes the value of the ZDT6 multi-objective benchmark function.
% SCORES = ZDT6FCN(X) computes the value of the ZDT6 function
% at point X. ZDT6FCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2 in which each row contains the function
% values for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/zdt6fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zdt6fcn(x)
    n = size(x, 2);
    assert(n >= 2, 'The ZDT6 function requires at least a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 2);
    scores(:, 1) = 1.0 - exp(-4.0 * x(:, 1)) .* (sin(6.0 * pi * x(:, 1))).^6;
    g = 1.0 + 9.0 * (sum(x(:, 2:end), 2) / (n - 1)).^0.25;
    h = 1.0 - (scores(:, 1) ./ g).^2;
    scores(:, 2) = g .* h;
end
