% Computes the value of the Biggs EXP04 function.
% SCORES = BIGGSEXP04FCN(X) computes the value of the Biggs EXP04
% function at point X. BIGGSEXP04FCN accepts a matrix of size M-by-4 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = biggsexp04fcn(x)
    n = size(x, 2);
    assert(n == 4, 'Biggs EXP04 function is only defined on a 4D space.')
    % X: M-by-4 matrix [x1, x2, x3, x4]

    i = (1:10)';
    ti = 0.1 * i;
    yi = exp(-ti) - 5 * exp(-10 * ti);

    x1 = x(:, 1)';
    x2 = x(:, 2)';
    x3 = x(:, 3)';
    x4 = x(:, 4)';

    % term1: x3 * exp(-ti * x1) (10xM)
    % term2: x4 * exp(-ti * x2) (10xM)
    term1 = x3 .* exp(-ti * x1);
    term2 = x4 .* exp(-ti * x2);

    residuals_sq = (term1 - term2 - yi).^2;
    scores = sum(residuals_sq, 1)';
end
