% Computes the value of the Bartels Conn benchmark function.
% SCORES = BARTELSCONNFCN(X) computes the value of the Bartels Conn
% function at point X. BARTELSCONNFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/bartelsconnfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bartelsconnfcn(x)

    n = size(x, 2);
    assert(n == 2, 'Bartels Conn function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = abs((X .^ 2) + (Y .^ 2) + (X .* Y)) + abs(sin(X)) + abs(cos(Y));
end
