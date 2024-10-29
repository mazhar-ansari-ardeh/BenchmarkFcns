% Computes the value of the Crowned Cross function.
% SCORES = CROWNEDCROSSFCN(X) computes the value of the Crowned Cross
% function at point X. CROWNEDCROSSFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = crownedcrossfcn(x)
  n = size(x, 2);
    assert(n == 2, 'The Crowned Cross function is defined only on the 2-D space.')

    X = x(:, 1);
    Y = x(:, 2);

    expcomponent = abs(100 - sqrt(X.^2 + Y.^2)/pi)
    scores = 0.0001 * (abs(exp(expcomponent) .* sin(X) .* sin(Y)) + 1) .^ 0.1;
