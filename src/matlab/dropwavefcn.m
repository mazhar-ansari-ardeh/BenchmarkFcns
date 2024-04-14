% Computes the value of the Drop-Wave benchmark function.
% SCORES = DROPWAVEFCN(X) computes the value of the Drop-Wave function at
% point X. DROPWAVEFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/dropwavefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = dropwavefcn(x)
    n = size(x, 2);
    assert(n == 2, 'Drop-Wave function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    numeratorcomp = 1 + cos(12 * sqrt(X .^ 2 + Y .^ 2));
    denumeratorcom = (0.5 * (X .^ 2 + Y .^ 2)) + 2;
    scores = - numeratorcomp ./ denumeratorcom;
end
