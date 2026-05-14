% Computes the value of the CEC 2009 CF9 constrained multi-objective benchmark function.
function scores = cf9fcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    [m, n] = size(x);
    x1 = x(:, 1);
    x2 = x(:, 2);
    j = 3:n;

    yj = x(:, 3:end) - sin(6 * pi * x1 + (j * pi) / n);

    j1_idx = mod(j - 1, 3) == 0;
    j2_idx = mod(j - 2, 3) == 0;
    j3_idx = ~(j1_idx | j2_idx);

    scores = zeros(m, 3 + return_constraints);

    common1 = cos(0.5 * pi * x1);
    common2 = cos(0.5 * pi * x2);
    common3 = sin(0.5 * pi * x2);
    common4 = sin(0.5 * pi * x1);

    scores(:, 1) = common1 .* common2 + (2/sum(j1_idx)) * sum(yj(:, j1_idx).^2, 2);
    scores(:, 2) = common1 .* common3 + (2/sum(j2_idx)) * sum(yj(:, j2_idx).^2, 2);
    scores(:, 3) = common4 + (2/sum(j3_idx)) * sum(yj(:, j3_idx).^2, 2);

    if return_constraints
        N = 2.0; a = 2.0;
        term = (scores(:, 1).^2 + scores(:, 2).^2) ./ (1.0 - scores(:, 3).^2);
        scores(:, 4) = 1.0 - term + a * sin(N * pi * (term + 1.0));
    end
end
