% Computes the value of the MaF8 multi-objective benchmark function.
function scores = maf8fcn(x, num_objectives)
    if nargin < 2, num_objectives = 3; end
    [m, n] = size(x);
    M = num_objectives;
    assert(n == 2, 'MaF8 requires a 2D space.');

    scores = zeros(m, M);
    for i = 1:M
        p1 = sin(2.0 * pi * (i - 1) / M);
        p2 = cos(2.0 * pi * (i - 1) / M);
        scores(:, i) = sqrt((x(:, 1) - p1).^2 + (x(:, 2) - p2).^2);
    end
end
