% Computes the value of Stretched V Sine benchmark function.
% SCORES = STRETCHEDVSINEFCN(X) computes the value of the Stretched V Sine
% function at point X. STRETCHEDVSINEFCN accepts a matrix of size M-by-N
% and returns a vector SCORES of size M-by-1 in which each row contains
% the function value for each row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/stretchedvsinefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function f = stretchedvsinefcn(x)
    [m, n] = size(x);
    if n < 2
        f = zeros(m, 1);
        return
    end

    x1 = x(:, 1:n-1);
    x2 = x(:, 2:n);

    v = x1.^2 + x2.^2;
    f = sum((v.^0.25) .* (sin(50 * (v.^0.1)).^2 + 0.1), 2);
end
