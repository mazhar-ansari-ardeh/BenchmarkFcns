% Computes the value of the Step benchmark function (De Jong N. 3).
% SCORES = STEPFCN(X) computes the value of the Step
% function at point X. STEPFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = stepfcn(x)
    scores = sum(floor(x + 0.5).^2, 2);
end
