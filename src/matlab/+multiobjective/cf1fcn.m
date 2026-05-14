% Computes the value of the CEC 2009 CF1 constrained multi-objective benchmark function.
function scores = cf1fcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;
    exponent = 0.5 * (1.0 + 3.0 * (j - 2) / (n - 2));
    yj = x(:, 2:end) - x1.^exponent;

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    scores = zeros(m, 2 + return_constraints);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * sum(yj(:, j1_idx).^2, 2);
    scores(:, 2) = 1 - x1 + (2/sum(j2_idx)) * sum(yj(:, j2_idx).^2, 2);

    if return_constraints
        N = 10; a = 1;
        scores(:, 3) = 1 - (scores(:, 1) + scores(:, 2)) + a * abs(sin(N * pi * (scores(:, 1) - scores(:, 2) + 1)));
    end
end
