% Computes the value of the MaF9 multi-objective benchmark function.
function scores = maf9fcn(x, num_objectives)
    if nargin < 2, num_objectives = 3; end
    [m, n] = size(x);
    M = num_objectives;
    assert(n == 2, 'MaF9 requires a 2D space.');

    scores = zeros(m, M);
    for i = 1:M
        alpha = (2.0 * i - 1.0) * pi / M;
        scores(:, i) = abs(x(:, 1) * cos(alpha) + x(:, 2) * sin(alpha) - cos(pi / M));
    end
end
