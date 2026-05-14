% Computes the value of the MaF1 multi-objective benchmark function.
function scores = maf1fcn(x, num_objectives)
    if nargin < 2, num_objectives = 3; end
    [m, n] = size(x);
    M = num_objectives;
    k = n - M + 1;

    xm = x(:, M:n);
    g = sum((xm - 0.5).^2, 2);

    scores = zeros(m, M);
    for i = 1:M
        prod = ones(m, 1);
        for j = 1:(M - i)
            prod = prod .* x(:, j);
        end
        if i > 1
            prod = prod .* (1.0 - x(:, M - i + 1));
        end
        scores(:, i) = 0.5 * (1.0 + g) .* (1.0 - prod);
    end
end
