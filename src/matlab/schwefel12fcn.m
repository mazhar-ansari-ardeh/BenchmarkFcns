% Computes the value of the Schwefel 1.2 (Double Sum) benchmark function.
% SCORES = SCHWEFEL12FCN(X) computes the value of the Schwefel 1.2
% function at point X. SCHWEFEL12FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = schwefel12fcn(x)
    cumsums = cumsum(x, 2);
    scores = sum(cumsums.^2, 2);
end
