% Computes the value of the BNH (Binh and Korn) multi-objective benchmark function.
% SCORES = BNHFCN(X) computes the value of the BNH function
% at point X. BNHFCN accepts a matrix of size M-by-2 and returns
% a matrix SCORES of size M-by-2.
function scores = bnhfcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    n = size(x, 2);
    assert(n == 2, 'The BNH function is only defined on a 2D space.');
    m = size(x, 1);
    cols = 2;
    if return_constraints
        cols = 4;
    end
    scores = zeros(m, cols);
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores(:, 1) = 4 * x1.^2 + 4 * x2.^2;
    scores(:, 2) = (x1 - 5).^2 + (x2 - 5).^2;
    if return_constraints
        scores(:, 3) = (x1 - 5).^2 + x2.^2 - 25;
        scores(:, 4) = 7.7 - (x1 - 8).^2 - (x2 + 3).^2;
    end
end
