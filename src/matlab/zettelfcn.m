% Computes the value of the Zettel function.
% SCORES = ZETTELFCN(X) computes the value of the Zettel
% function at point X. ZETTELFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zettelfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Zettel function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = 0.25 * X - (X.^2 - 2*X + Y.^2).^2;
end
