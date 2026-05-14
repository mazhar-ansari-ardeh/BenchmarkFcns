% Computes the value of the MaF2 multi-objective benchmark function.
function scores = maf2fcn(x, num_objectives)
    if nargin < 2, num_objectives = 3; end
    [m, n] = size(x);
    M = num_objectives;
    K = n - M + 1;

    scores = zeros(m, M);
    for i = 1:M
        start_idx = M + (i - 1) * floor(K / M);
        if i == M
            end_idx = n;
        else
            end_idx = M + i * floor(K / M) - 1;
        end

        gi = zeros(m, 1);
        if start_idx <= end_idx
            gi = sum((x(:, start_idx:end_idx) - 0.5).^2, 2);
        end

        prod = ones(m, 1);
        for j = 1:(M - i)
            prod = prod .* cos(x(:, j) * pi / 2.0);
        end
        if i > 1
            prod = prod .* sin(x(:, M - i + 1) * pi / 2.0);
        end
        scores(:, i) = (1.0 + gi) .* prod;
    end
end
