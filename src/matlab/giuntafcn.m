% Computes the value of the Giunta function.
% SCORES = GIUNTAFCN(X) computes the value of the Alpine N. 1
% function at point X. GIUNTAFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/giuntafcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = giuntafcn(x)
    scores = 0.6 + sum(sin(1 - (16/15) * x).^2 - (1/50) * sin(4 - (64/15) * x) - sin(1 - (16/15) * x), 2);
end
