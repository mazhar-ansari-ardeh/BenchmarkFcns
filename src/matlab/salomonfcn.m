% Computes the value of the Salomon's benchmark function.
% SCORES = SALOMONFCN(X) computes the value of the Salomon's
% function at point X. SALOMONFCN accepts a matrix of size M-by-N
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/salomonfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = salomonfcn(x)
    x2 = x .^ 2;
    sumx2 = sum(x2, 2);
    sqrtsx2 = sqrt(sumx2);

    scores = 1 - cos(2 .* pi .* sqrtsx2) + (0.1 * sqrtsx2);
end
