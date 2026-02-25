% Computes the value of the Biggs EXP02 function.
% SCORES = BIGGSEXP02FCN(X) computes the value of the Biggs EXP02
% function at point X. BIGGSEXP02FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = biggsexp02fcn(x)
    i = (1:10)';
    ti = 0.1 * i; % Column vector (10x1)
    yi = exp(-ti) - 5 * exp(-10 * ti); % Column vector (10x1)

    x1 = x(:, 1)';
    x2 = x(:, 2)';

    term1 = exp(-ti * x1);
    term2 = 5 * exp(-ti * x2);

    residuals_sq = (term1 - term2 - yi).^2;

    scores = sum(residuals_sq, 1)';
end
