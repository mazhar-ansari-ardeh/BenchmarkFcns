% Computes the value of the CEC 2009 UF7 multi-objective benchmark function.
function scores = uf7fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;
    yj = x(:, 2:end) - sin(6*pi*x1 + (j*pi)/n);

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    yj1 = yj(:, j1_idx);
    yj2 = yj(:, j2_idx);

    scores = zeros(m, 2);
    scores(:, 1) = x1.^0.2 + (2/sum(j1_idx)) * sum(yj1.^2, 2);
    scores(:, 2) = 1 - x1.^0.2 + (2/sum(j2_idx)) * sum(yj2.^2, 2);
end
