% Computes the value of the Biggs EXP06 function.
% SCORES = BIGGSEXP06FCN(X) computes the value of the Biggs EXP06
% function at point X. BIGGSEXP06FCN accepts a matrix of size M-by-6 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = biggsexp06fcn(x)
    n = size(x, 2);
    assert(n == 6, 'Biggs EXP06 function is only defined on a 6D space.')

    i = (1:10)';
    ti = 0.1 * i;
    yi = exp(-ti) - 5*exp(-10*ti) + 3*exp(-4*ti);

    x1 = x(:, 1)'; x2 = x(:, 2)'; x3 = x(:, 3)';
    x4 = x(:, 4)'; x5 = x(:, 5)'; x6 = x(:, 6)';

    term1 = x3 .* exp(-ti * x1);
    term2 = x4 .* exp(-ti * x2);
    term3 = x6 .* exp(-ti * x5);

    residuals_sq = (term1 - term2 + term3 - yi).^2;
    scores = sum(residuals_sq, 1)';
end
