% Computes the value of the Beale benchmark function.
% SCORES = BEALEFCN(X) computes the value of the Beale function at
% point X. BEALEFCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/bealefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bealefcn(x)
    n = size(x, 2);
    assert(n == 2, 'Beale''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    scores = (1.5 - X + (X .* Y)).^2 + ...
             (2.25 - X + (X .* (Y.^2))).^2 + ...
             (2.625 - X + (X .* (Y.^3))).^2;
end
