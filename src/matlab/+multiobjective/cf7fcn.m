% Computes the value of the CEC 2009 CF7 constrained multi-objective benchmark function.
function scores = cf7fcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;

    yj = zeros(m, n-1);
    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    yj(:, j1_idx) = x(:, j(j1_idx)) - 0.8 * x1 .* cos(6 * pi * x1 + (j(j1_idx) * pi) / n);
    yj(:, j2_idx) = x(:, j(j2_idx)) - 0.8 * x1 .* sin(6 * pi * x1 + (j(j2_idx) * pi) / n);

    h = @(t) 2 * t.^2 - cos(4 * pi * t) + 1;

    scores = zeros(m, 2 + 2 * return_constraints);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * sum(h(yj(:, j1_idx)), 2);
    scores(:, 2) = (1 - x1).^2 + (2/sum(j2_idx)) * sum(h(yj(:, j2_idx)), 2);

    if return_constraints
        scores(:, 3) = 0.5 * x1 - 0.25 + 0.8 * x1 .* sin(6 * pi * x1 + 2 * pi / n) - x(:, 2);
        scores(:, 4) = 0.5 * x1 - 0.25 + 0.8 * x1 .* sin(6 * pi * x1 + 6 * pi / n) - x(:, 6);
    end
end
