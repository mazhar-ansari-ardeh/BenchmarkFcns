% Computes the value of the Deckkers-Aarts function.
% SCORES = DECKKERSAARTSFCN(X) computes the value of the Deckkers-Aarts
% function at point X. DECKKERSAARTSFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/deckkersaartsfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = deckkersaartsfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Deckkers-Aarts function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (100000 * X.^2) + Y.^2 + - (X.^2 + Y.^2).^2 + (10^-5) * (X.^2 + Y.^2 ) .^4;
end
