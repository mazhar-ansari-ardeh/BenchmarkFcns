% Computes the value of the MaF5 multi-objective benchmark function.
function scores = maf5fcn(x, num_objectives)
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
            prod = prod .* cos(x(:, j).^100.0 * pi / 2.0);
        end
        if i > 1
            prod = prod .* sin(x(:, M - i + 1).^100.0 * pi / 2.0);
        end
        scores(:, i) = 10.^(i-1) * (1.0 + g) .* prod;
    end
end
