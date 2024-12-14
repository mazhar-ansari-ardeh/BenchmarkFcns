% Computes the value of the Zero-sum function.
% SCORES = ZEROSUMFCN(X) computes the value of the Zero-sum
% function at point X. ZEROSUMFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zerosumfcn(x)
    s = sum(x, 2);
    scores = 1 + sqrt(10000 * abs(s));
    scores(scores == 1) = 0;
end
