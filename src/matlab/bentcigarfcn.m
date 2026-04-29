% Computes the value of the Bent Cigar benchmark function.
% SCORES = BENTCIGARFCN(X) computes the value of the Bent Cigar
% function at point X. BENTCIGARFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bentcigarfcn(x)
    n = size(x, 2);

    scores = x(:, 1).^2;
    if n > 1
        scores = scores + 1e6 * sum(x(:, 2:end).^2, 2);
    end
end
