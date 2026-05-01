% Computes the value of the Mishra's Bird function.
% SCORES = MISHRABIRDFCN(X) computes the value of the Mishra's Bird
% function at point X. MISHRABIRDFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/mishrabirdfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = mishrabirdfcn(x)

    n = size(x, 2);
    assert(n == 2, 'Mishra''s Bird function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = sin(Y) .* exp((1 - cos(X)).^2) + ...
        cos(X) .* exp((1 - sin(Y)) .^ 2) + ...
        (X - Y) .^ 2;
end
