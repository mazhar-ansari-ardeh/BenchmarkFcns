% Computes the value of the CEC 2009 UF6 multi-objective benchmark function.
function scores = uf6fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;
    yj = x(:, 2:end) - sin(6*pi*x1 + (j*pi)/n);

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    yj1 = yj(:, j1_idx);
    yj2 = yj(:, j2_idx);
    j1 = j(j1_idx);
    j2 = j(j2_idx);

    g1 = 4*sum(yj1.^2, 2) - 2*prod(cos(20*yj1*pi./sqrt(j1)), 2) + 2;
    g2 = 4*sum(yj2.^2, 2) - 2*prod(cos(20*yj2*pi./sqrt(j2)), 2) + 2;

    N = 2; epsilon = 0.1;
    common = max(0, 2*(0.5/N + epsilon) * sin(2*N*pi*x1));

    scores = zeros(m, 2);
    scores(:, 1) = x1 + common + (2/sum(j1_idx)) * g1;
    scores(:, 2) = 1 - x1 + common + (2/sum(j2_idx)) * g2;
end
