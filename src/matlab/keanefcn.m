% Computes the value of the Keane function.
% SCORES = KEANEFCN(X) computes the value of the Keane function at point X.
% KEANEFCN accepts a matrix of size M-by-2 and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/keanefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = keanefcn(x)
    n = size(x, 2);
    assert(n == 2, 'Keane function is defined only on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    numeratorcomp = (sin(X - Y) .^ 2) .* (sin(X + Y) .^ 2);
    denominatorcomp = sqrt(X .^2 + Y .^2);
    scores = - numeratorcomp ./ denominatorcomp;
end
