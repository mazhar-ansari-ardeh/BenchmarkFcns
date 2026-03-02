% Computes the value of the Biggs EXP05 function.
% SCORES = BIGGSEXP05FCN(X) computes the value of the Biggs EXP05
% function at point X. BIGGSEXP05FCN accepts a matrix of size M-by-5 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = biggsexp05fcn(x)
    n = size(x, 2);
    assert(n == 5, 'Biggs EXP05 function is only defined on a 5D space.')

    i = (1:10)';
    ti = 0.1 * i;
    yi = exp(-ti) - 5 * exp(-10 * ti);

    x1 = x(:, 1)';
    x2 = x(:, 2)';
    x3 = x(:, 3)';
    x4 = x(:, 4)';
    x5 = x(:, 5)';

    term1 = x3 .* exp(-ti * x1);
    term2 = x4 .* exp(-ti * x2);
    term3 = 3 * exp(-ti * x5);

    residuals_sq = (term1 - term2 + term3 - yi).^2;
    scores = sum(residuals_sq, 1)';
end
