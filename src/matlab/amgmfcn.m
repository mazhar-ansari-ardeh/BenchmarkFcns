% Computes the value of the AMGM function.
% SCORES = AMGMFCN(X) computes the value of the AMGM
% function at point X. AMGMFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = amgmfcn(x)
    n = size(x, 2);
    scores = (prod(x, 2) .^ (1 / n) - mean(x, 2)) .^ 2;
end
