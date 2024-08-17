% Computes the value of the Treccani's function.
% SCORES = TRECCANIFCN(X) computes the value of the Xin-She Yang
% function at point X. TRECCANIFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = treccanifcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Treccani function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (X .^ 4) + 4 * (X .^ 3) + 4 * (X .^ 2) + (Y .^ 2);
end
