% Computes the value of the El-Attar function.
% SCORES = ELATTARFCN(X) computes the value of the El-Attar
% function at point X. ELATTARFCN accepts a matrix of size M-by-3 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/elattarfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = elattarfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The El-Attar et al. function is defined only on the 2-D space.')

    X = x(:, 1);
    Y = x(:, 2);

    scores = (X .^ 2 + Y - 10) .^ 2 + (X + Y .^ 2 - 7) .^ 2 + (X .^ 2 + Y .^ 3 - 1) .^ 2;
end
