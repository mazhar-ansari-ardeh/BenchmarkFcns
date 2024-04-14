% Computes the value of the Griewank benchmark function.
% SCORES = GRIEWANKFCN(X) computes the value of the Griewank's
% function at point X. GRIEWANKFCN accepts a matrix of size M-by-N
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/griewankfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = griewankfcn(x)

    n = size(x, 2);

    sumcomp = 0;
    prodcomp = 1;

    for i = 1:n
        sumcomp = sumcomp + (x(:, i) .^ 2);
        prodcomp = prodcomp .* (cos(x(:, i) / sqrt(i)));
    end

    scores = (sumcomp / 4000) - prodcomp + 1;
end
