% Computes the value of the MaF7 multi-objective benchmark function.
function scores = maf7fcn(x, num_objectives)
    if nargin < 2, num_objectives = 3; end
    [m, n] = size(x);
    M = num_objectives;
    k = n - M + 1;

    xm = x(:, M:n);
    g = 1.0 + 9.0 * mean(xm, 2);

    scores = zeros(m, M);
    for i = 1:(M - 1)
        scores(:, i) = x(:, i);
    end

    h = M * ones(m, 1);
    for i = 1:(M - 1)
        h = h - (scores(:, i) ./ (1.0 + g)) .* (1.0 + sin(3.0 * pi * scores(:, i)));
    end
    scores(:, M) = (1.0 + g) .* h;
end
