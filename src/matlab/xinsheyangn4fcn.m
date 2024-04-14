% Computes the value of the Xin-She Yang N. 4 function.
% SCORES = XINSHEYANGN4FCN(X) computes the value of the Xin-She Yang N. 4
% function at point X. XINSHEYANGN4FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/xinsheyangn4fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = xinsheyangn4fcn(x)
     scores = (sum(sin(x) .^2, 2) - exp(-sum(x .^ 2, 2))) .* exp(-sum(sin(sqrt(abs(x))) .^2, 2));
end
