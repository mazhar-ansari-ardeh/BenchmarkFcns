% Computes the value of the Wolfe function.
% SCORES = WOLFEFCN(X) computes the value of the Wolfe
% function at point X. WOLFEFCN accepts a matrix of size M-by-3 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/wolfefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = wolfefcn(x)
    n = size(x, 2);
    assert(n == 3, 'The Wolfe function is defined only on the 3-D space.')
    X = x(:, 1);
    Y = x(:, 2);
    Z = x(:, 3);

    scores = (4/3)*(((X .^ 2 + Y .^ 2) - (X .* Y)).^(0.75)) + Z;
end
