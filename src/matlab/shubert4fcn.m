% Computes the value of the Shubert 4 function.
% SCORES = SHUBERT4FCN(X) computes the value of the Shubert 4
% function at point X. SHUBERT4FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/shubert4fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = shubert4fcn(x)
    [m, n] = size(x);
    col_sums = zeros(m, n);

    for j = 1:5
        col_sums = col_sums + cos((j + 1) * x + j);
    end

    scores = sum(col_sums, 2);
end
