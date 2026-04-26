% Computes the value of the Osyczka and Kundu multi-objective benchmark function.
% SCORES = OSYCZKAKUNDUFCN(X) computes the value of the Osyczka and Kundu function
% at point X. OSYCZKAKUNDUFCN accepts a matrix of size M-by-6 and returns
% a matrix SCORES of size M-by-2.
%
% If return_constraints is True, returns an M-by-8 matrix where the last six columns
% contain the constraint violations (values > 0 are violations).
function scores = osyczkakundufcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    n = size(x, 2);
    assert(n == 6, 'The Osyczka and Kundu function is only defined on a 6D space.');
    m = size(x, 1);
    cols = 2;
    if return_constraints
        cols = 8;
    end
    scores = zeros(m, cols);

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);
    x5 = x(:, 5);
    x6 = x(:, 6);

    scores(:, 1) = -(25 * (x1 - 2).^2 + (x2 - 2).^2 + (x3 - 1).^2 + (x4 - 4).^2 + (x5 - 1).^2);
    scores(:, 2) = x1.^2 + x2.^2 + x3.^2 + x4.^2 + x5.^2 + x6.^2;

    if return_constraints
        scores(:, 3) = 2 - x1 - x2;
        scores(:, 4) = x1 + x2 - 6;
        scores(:, 5) = x2 - x1 - 2;
        scores(:, 6) = x1 - 3*x2 - 2;
        scores(:, 7) = (x3 - 3).^2 + x4 - 4;
        scores(:, 8) = 4 - (x5 - 3).^2 - x6;
    end
end
