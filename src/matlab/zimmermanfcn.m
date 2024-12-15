% Computes the value of the Zimmerman function.
% SCORES = ZIMMERMANFCN(X) computes the value of the Zettel
% function at point X. ZIMMERMANFCN accepts a matrix of size M-by-t and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zimmermanfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Zimmerman function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);

    zh1 = 9 - X - Y
    zh2 = (X - 3).^2 + (Y - 2).^2 - 16
    zh3 = X .* Y - 14
    % zp(zh2).*sign(zh2)

    scores = max([zh1, zp(zh2).*sign(zh2), zp(zh3) .* sign(zh3), zp(-X) .* sign(X), zp(-Y) .* sign(Y)]);
end

function ret = zp(t)
    ret = 100 * ( 1 + t);
end
