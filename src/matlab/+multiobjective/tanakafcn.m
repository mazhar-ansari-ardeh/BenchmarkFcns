% Computes the value of the Tanaka multi-objective benchmark function.
% SCORES = TANAKAFCN(X) computes the value of the Tanaka function at point X.
% TANAKAFCN accepts a matrix of size M-by-2 and returns a matrix SCORES of
% size M-by-2.
%
% If return_constraints is True, returns an M-by-4 matrix where the last two columns
% contain the constraint violations (values > 0 are violations).
function scores = tanakafcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    n = size(x, 2);
    assert(n == 2, 'The Tanaka function is only defined on a 2D space.');
    m = size(x, 1);
    cols = 2;
    if return_constraints
        cols = 4;
    end
    scores = zeros(m, cols);

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores(:, 1) = x1;
    scores(:, 2) = x2;

    if return_constraints
        % C1: x1^2 + x2^2 - 1 - 0.1*cos(16*atan2(x1, x2)) >= 0
        % In <= 0 form: 1 + 0.1*cos(16*atan2(x1, x2)) - x1^2 - x2^2 <= 0
        theta = atan2(x1, x2);
        scores(:, 3) = 1.0 + 0.1 * cos(16 * theta) - x1.^2 - x2.^2;

        % C2: (x1 - 0.5)^2 + (x2 - 0.5)^2 <= 0.5
        % In <= 0 form: (x1 - 0.5)^2 + (x2 - 0.5)^2 - 0.5 <= 0
        scores(:, 4) = (x1 - 0.5).^2 + (x2 - 0.5).^2 - 0.5;
    end
end
