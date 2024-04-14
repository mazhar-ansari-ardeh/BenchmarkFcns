% Computes the value of the Eggholder benchmark function.
% SCORES = EGGHOLDERFCN(X) computes the value of the Eggholder
% function at point X. EGGHOLDERFCN accepts a matrix of size M-by-2
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/eggholderfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = eggholderfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Eggholder function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    sin1component = sin(sqrt(abs( (X / 2) + Y + 47)));
    sin2component = sin(sqrt(abs( X - Y + 47)));

    scores = -(Y + 47) .* sin1component - (X .* sin2component);
end
