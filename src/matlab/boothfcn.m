% Computes the value of the Booth benchmark function.
% SCORES = BOOTHFCN(X) computes the value of the Booth's function at
% point X. BOOTHFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/boothfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = boothfcn(x)

    n = size(x, 2);
    assert(n == 2, 'Booth''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (X + (2 * Y) - 7).^2 + ( (2 * X) + Y - 5).^2;
end
