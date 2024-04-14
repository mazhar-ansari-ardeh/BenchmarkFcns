% Computes the value of the McCormick benchmark function.
% SCORES = MCCORMICKFCN(X) computes the value of the McCormick function
% at point X. MCCORMICKFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/mccormickfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = mccormickfcn(x)

    n = size(x, 2);
    assert(n == 2, 'The McCormick function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = sin(X + Y) + ((X - Y) .^2 ) - 1.5 * X + 2.5 * Y + 1;
end
