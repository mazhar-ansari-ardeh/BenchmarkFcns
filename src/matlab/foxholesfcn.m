% Computes the value of the Foxholes benchmark function.
% SCORES = FOXHOLESFCN(X) computes the value of the Foxholes
% function at point X. FOXHOLESFCN accepts a matrix of size M-by-2
% and returns a vector SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/foxholesfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = foxholesfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Foxholes function is only defined on a 2D space.')

    a1 = [-32, -16, 0, 16, 32];
    a = zeros(25, 2);
    for i = 1:25
        a(i, 1) = a1(mod(i-1, 5) + 1);
        a(i, 2) = a1(floor((i-1)/5) + 1);
    end

    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:25
        diff1_6 = (x(:, 1) - a(i, 1)).^6;
        diff2_6 = (x(:, 2) - a(i, 2)).^6;
        scores = scores + 1.0 ./ (i + diff1_6 + diff2_6);
    end
    scores = 1.0 ./ (0.002 + scores);
end
