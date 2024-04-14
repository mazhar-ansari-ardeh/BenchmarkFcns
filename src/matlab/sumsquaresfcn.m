% Computes the value of the Sum Squares function.
% SCORES = SUMSQUARESFCN(X) computes the value of the Sum Squares
% function at point X. SUMSQUARESFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/sumsquaresfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = sumsquaresfcn(x)

   [m, n] = size(x);
   x2 = x .^2;
   I = repmat(1:n, m, 1);
   scores = sum( I .* x2, 2);

end
