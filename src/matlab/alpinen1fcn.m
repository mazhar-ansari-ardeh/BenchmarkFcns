% Computes the value of the Alpine N. 1 function.
% SCORES = ALPINEN1FCN(X) computes the value of the Alpine N. 1
% function at point X. ALPINEN1FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/alpinen1fcn
% See also: alpinen2fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = alpinen1fcn(x)
     scores = sum(abs(x .* sin(x) + 0.1 * x), 2);
end
