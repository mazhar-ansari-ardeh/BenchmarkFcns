% Computes the value of the Chichinadze function.
% SCORES = CHICHINADZEFCN(X) computes the value of the Xin-She Yang
% function at point X. CHICHINADZEFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = chichinadzefcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Chichinadze function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = X .^ 2 - 12 * X + 8 * sin(5 * pi * X / 2) + 10 * cos(pi * X / 2) + 11 - 0.2 * sqrt(5) ./ exp(((Y - 0.5) .^ 2)/2);
end
