% Computes the value of the Trid function.
% SCORES = TRIDFCN(X) computes the value of the Xin-She Yang
% function at point X. TRIDFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/tridfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = tridfcn(x)
    sum((x - 1) .^ 2, 2)
    scores = sum((x - 1) .^ 2, 2) - sum(x(:, 2:end) .* x(:, 1:end-1), 2);
end
