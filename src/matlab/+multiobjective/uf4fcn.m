% Computes the value of the CEC 2009 UF4 multi-objective benchmark function.
function scores = uf4fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;
    yj = x(:, 2:end) - sin(6*pi*x1 + (j*pi)/n);

    h_yj = 2*yj.^2 - cos(4*pi*yj) + 1;

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    scores = zeros(m, 2);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * sum(h_yj(:, j1_idx), 2);
    scores(:, 2) = 1 - x1.^2 + (2/sum(j2_idx)) * sum(h_yj(:, j2_idx), 2);
end
