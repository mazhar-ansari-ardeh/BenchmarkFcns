% Computes the value of the CEC 2009 CF2 constrained multi-objective benchmark function.
function scores = cf2fcn(x, return_constraints)
    if nargin < 2
        return_constraints = false;
    end
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;

    yj = zeros(m, n-1);
    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    % j is odd
    yj(:, j1_idx) = x(:, j(j1_idx)) - sin(6 * pi * x1 + (j(j1_idx) * pi) / n);
    % j is even
    yj(:, j2_idx) = x(:, j(j2_idx)) - cos(6 * pi * x1 + (j(j1_idx == 0) * pi) / n);
    % Wait, the index for j(j2_idx) is correct, but let's be cleaner

    % Recalculate yj properly vectorized
    for jj = 2:n
        if mod(jj, 2) ~= 0
            yj(:, jj-1) = x(:, jj) - sin(6 * pi * x1 + (jj * pi) / n);
        else
            yj(:, jj-1) = x(:, jj) - cos(6 * pi * x1 + (jj * pi) / n);
        end
    end

    j1_logic = mod(j, 2) ~= 0;
    j2_logic = mod(j, 2) == 0;

    scores = zeros(m, 2 + return_constraints);
    scores(:, 1) = x1 + (2/sum(j1_logic)) * sum(yj(:, j1_logic).^2, 2);
    scores(:, 2) = 1 - sqrt(x1) + (2/sum(j2_logic)) * sum(yj(:, j2_logic).^2, 2);

    if return_constraints
        N = 2.0; a = 1.0;
        sqrt_f1 = sqrt(scores(:, 1));
        scores(:, 3) = 1.0 - scores(:, 2) - sqrt_f1 + a * sin(N * pi * (sqrt_f1 - scores(:, 2) + 1.0));
    end
end
