% Computes the value of the Deb N.1 function.
% SCORES = DEBN1FCN(X) computes the value of the Deb N.1
% function at point X. DEBN1FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = debn1fcn(x)
    n = size(x, 2);
    scores = - sum(sin(5 * pi * x).^6, 2) / n;
end
