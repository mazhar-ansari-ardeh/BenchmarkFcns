% Computes the value of the CEC 2009 CF4 constrained multi-objective benchmark function.
function scores = cf4fcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;

    yj = x(:, 2:end) - sin(6 * pi * x1 + (j * pi) / n);

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    scores = zeros(m, 2 + return_constraints);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * sum(yj(:, j1_idx).^2, 2);
    scores(:, 2) = 1 - x1 + (2/sum(j2_idx)) * sum(yj(:, j2_idx).^2, 2);

    if return_constraints
        scores(:, 3) = 0.5 * x1 - 0.25 + sin(6 * pi * x1 + 2 * pi / n) - x(:, 2);
    end
end
