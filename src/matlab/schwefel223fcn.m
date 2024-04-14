% Computes the value of the Schwefel 2.23 function.
% SCORES = SCHWEFEL223FCN(X) computes the value of the Schwefel 2.23
% function at point X. SCHWEFEL223FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/schwefel223fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = schwefel223fcn(x)
    scores = sum(x .^10, 2);
end
