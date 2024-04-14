% Computes the value of the Xin-She Yang N. 2 function.
% SCORES = XINSHEYANGN2FCN(X) computes the value of the Xin-She Yang N. 2
% function at point X. XINSHEYANGN2FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/xinsheyangn2fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = xinsheyangn2fcn(x)
     scores = sum(abs(x), 2) .* exp(-sum(sin(x .^2), 2));
end
