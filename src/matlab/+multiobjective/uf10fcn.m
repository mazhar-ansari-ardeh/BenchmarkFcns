% Computes the value of the CEC 2009 UF10 multi-objective benchmark function.
function scores = uf10fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    x2 = x(:, 2);
    j = 3:n;

    yj = x(:, 3:end) - 2*x2.*sin(2*pi*x1 + (j*pi)/n);
    h_yj = 4*yj.^2 - cos(8*pi*yj) + 1;

    j1_idx = mod(j-1, 3) == 0;
    j2_idx = mod(j-2, 3) == 0;
    j3_idx = ~(j1_idx | j2_idx);

    scores = zeros(m, 3);
    scores(:, 1) = cos(0.5*pi*x1).*cos(0.5*pi*x2) + (2/sum(j1_idx)) * sum(h_yj(:, j1_idx), 2);
    scores(:, 2) = cos(0.5*pi*x1).*sin(0.5*pi*x2) + (2/sum(j2_idx)) * sum(h_yj(:, j2_idx), 2);
    scores(:, 3) = sin(0.5*pi*x1) + (2/sum(j3_idx)) * sum(h_yj(:, j3_idx), 2);
end
