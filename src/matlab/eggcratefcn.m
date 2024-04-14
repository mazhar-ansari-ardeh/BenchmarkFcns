% Computes the value of the Egg Crate function.
% SCORES = EGGCRATEFCN(X) computes the value of the Egg Crate
% function at point X. EGGCRATEFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/eggcratefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = eggcratefcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Egg Crate function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = X.^2 + Y.^2 + (25 * (sin(X).^2 + sin(Y).^2));
end
