% Computes the value of the Exponential function.
% SCORES = EXPONENTIALFCN(X) computes the value of the Exponential
% function at point X. EXPONENTIALFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/exponentialfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = exponentialfcn(x)
   x2 = x .^2;

   scores = -exp(-0.5 * sum(x2, 2));
end
