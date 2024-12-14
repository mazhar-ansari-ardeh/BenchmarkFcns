% Computes the value of the Zirilli function.
% SCORES = ZIRILLIFCN(X) computes the value of the Zirilli
% function at point X. ZIRILLIFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zirillifcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Zirilli function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = 0.25 * X.^4 - 0.5 * X.^2 + 0.1 * X + 0.5 * Y.^2;
end
