% Computes the value of the CEC 2009 UF9 multi-objective benchmark function.
function scores = uf9fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    x2 = x(:, 2);
    j = 3:n;

    yj = x(:, 3:end) - 2*x2.*sin(2*pi*x1 + (j*pi)/n);

    j1_idx = mod(j-1, 3) == 0;
    j2_idx = mod(j-2, 3) == 0;
    j3_idx = ~(j1_idx | j2_idx);

    epsilon = 0.1;
    E = max(0, (1+epsilon)*(1 - 4*(2*x1-1).^2));

    scores = zeros(m, 3);
    scores(:, 1) = 0.5*(E + 2*x1).*x2 + (2/sum(j1_idx)) * sum(yj(:, j1_idx).^2, 2);
    scores(:, 2) = 0.5*(E + 2*x1).*(1-x2) + (2/sum(j2_idx)) * sum(yj(:, j2_idx).^2, 2);
    scores(:, 3) = 1 - x1 + (2/sum(j3_idx)) * sum(yj(:, j3_idx).^2, 2);
end
