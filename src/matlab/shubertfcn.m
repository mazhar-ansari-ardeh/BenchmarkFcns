% Computes the value of the Shubert function.
% SCORES = SHUBERTFCN(X) computes the value of the Shubert
% function at point X. SHUBERTFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/shubertfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = shubertfcn(x)
    [m, n] = size(x);
    col_sums = zeros(m, n);

    for j = 1:5
        col_sums = col_sums + j * cos((j + 1) * x + j);
    end

    scores = prod(col_sums, 2);
end
