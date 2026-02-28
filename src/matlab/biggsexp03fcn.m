% Computes the value of the Biggs EXP03 function.
% SCORES = BIGGSEXP03FCN(X) computes the value of the Biggs EXP03
% function at point X. BIGGSEXP03FCN accepts a matrix of size M-by-3 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = biggsexp03fcn(x)
    n = size(x, 2);
    assert(n == 3, 'Biggs EXP03 function is only defined on a 3D space.')
    i = (1:10)';
    ti = 0.1 * i;
    yi = exp(-ti) - 5 * exp(-10 * ti);

    x1 = x(:, 1)';
    x2 = x(:, 2)';
    x3 = x(:, 3)'; % The third parameter

    term1 = x3 .* exp(-ti * x1);
    term2 = 5 * exp(-ti * x2);

    residuals_sq = (term1 - term2 - yi).^2;

    scores = sum(residuals_sq, 1)';
end
