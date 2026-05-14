% Computes the value of the MaF6 multi-objective benchmark function.
function scores = maf6fcn(x, num_objectives)
    if nargin < 2, num_objectives = 3; end
    [m, n] = size(x);
    M = num_objectives;
    k = n - M + 1;
    I = 2;

    xm = x(:, M:n);
    g = sum((xm - 0.5).^2, 2);

    theta = zeros(m, M - 1);
    for j = 1:(I - 1)
        theta(:, j) = x(:, j) * pi / 2.0;
    end
    for j = I:(M - 1)
        theta(:, j) = (pi ./ (4.0 * (1.0 + g))) .* (1.0 + 2.0 * g .* x(:, j));
    end

    scores = zeros(m, M);
    for i = 1:M
        prod = ones(m, 1);
        for j = 1:(M - i)
            prod = prod .* cos(theta(:, j));
        end
        if i > 1
            prod = prod .* sin(theta(:, M - i + 1));
        end
        scores(:, i) = (1.0 + g) .* prod;
    end
end
