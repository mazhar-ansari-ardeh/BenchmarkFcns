% Computes the value of the Schwefel 2.20 function.
% SCORES = SCHWEFEL220FCN(X) computes the value of the Schwefel 2.20
% function at point X. SCHWEFEL220FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/schwefel220fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = schwefel220fcn(x)
    scores = sum(abs(x), 2);
end
