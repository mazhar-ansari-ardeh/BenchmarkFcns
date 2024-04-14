% Computes the value of the Qing function.
% SCORES = QINGFCN(X) computes the value of the Qing
% function at point X. QINGFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/qingfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = qingfcn(x)
    n = size(x, 2);
    x2 = x .^ 2;

    i_values = 1:n;
    scores = sum((x2 - i_values) .^ 2, 2);
end
