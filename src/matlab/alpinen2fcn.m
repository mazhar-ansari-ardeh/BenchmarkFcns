% Computes the value of the Alpine N. 2 function.
% SCORES = ALPINEN2FCN(X) computes the value of the Alpine N. 2
% function at point X. ALPINEN2FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/alpinen2fcn
% See also: alpinen1fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = alpinen2fcn(x)
     scores = prod(sqrt(x) .* sin(x), 2);
end
