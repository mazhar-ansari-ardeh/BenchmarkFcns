% Computes the value of the KITA bi-objective benchmark function.
% SCORES = KITAFCN(X, RETURN_CONSTRAINTS) computes the value of the KITA function
% at point X. KITAFCN accepts a matrix of size M-by-2 and returns
% a matrix SCORES of size M-by-2.
% If RETURN_CONSTRAINTS is true, returns an M-by-5 matrix where the last three columns
% contain the constraint violations (values > 0 are violations).
function scores = kitafcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    n = size(x, 2);
    assert(n >= 2, 'The KITA function requires at least a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    % Minimize -f1, -f2
    scores(:, 1) = x1.^2 - x2;
    scores(:, 2) = -0.5*x1 - x2 - 1.0;

    if return_constraints
        c1 = x1/6 + x2 - 13/2;
        c2 = x1/2 + x2 - 15/2;
        c3 = 5*x1 + x2 - 30;
        scores = [scores, c1, c2, c3];
    end
end
