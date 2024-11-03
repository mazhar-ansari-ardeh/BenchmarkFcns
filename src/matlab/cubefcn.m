% Computes the value of the Cube function.
% SCORES = CUBEFCN(X) computes the value of the Cube
% function at point X. CUBEFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = cubefcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Cube function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = 100 * (Y - X.^3).^2 + (1 - X).^2;
end
