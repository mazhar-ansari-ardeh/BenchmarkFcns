% Computes the value of the CEC 2009 CF3 constrained multi-objective benchmark function.
function scores = cf3fcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;

    yj = x(:, 2:end) - sin(6 * pi * x1 + (j * pi) / n);

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    s1 = sum(yj(:, j1_idx).^2, 2);
    s2 = sum(yj(:, j2_idx).^2, 2);

    p1 = prod(cos(20 * pi * yj(:, j1_idx) ./ sqrt(j(j1_idx))), 2);
    p2 = prod(cos(20 * pi * yj(:, j2_idx) ./ sqrt(j(j2_idx))), 2);

    scores = zeros(m, 2 + return_constraints);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * (4 * s1 - 2 * p1 + 2);
    scores(:, 2) = 1 - x1.^2 + (2/sum(j2_idx)) * (4 * s2 - 2 * p2 + 2);

    if return_constraints
        N = 2.0; a = 1.0;
        f1_sq = scores(:, 1).^2;
        scores(:, 3) = 1.0 - scores(:, 2) - f1_sq + a * sin(N * pi * (f1_sq - scores(:, 2) + 1.0));
    end
end
