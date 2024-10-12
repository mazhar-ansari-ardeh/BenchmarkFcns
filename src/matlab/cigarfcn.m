% Computes the value of the Cigar benchmark function.
% SCORES = CIGARFCN(X) computes the value of the Cigar function at
% point X. CIGARFCN accepts a matrix of size M-by-N and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = cigarfcn(x)
    scores = x(:, 1).^2 + 10^6 * sum(x(:, 2:end) .^ 2, 2);
end
