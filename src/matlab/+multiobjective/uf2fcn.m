% Computes the value of the CEC 2009 UF2 multi-objective benchmark function.
function scores = uf2fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;

    yj = zeros(m, n-1);

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    % For j in J1 (odd)
    j1 = j(j1_idx);
    yj(:, j1_idx) = x(:, j1) - (0.3*x1.^2 .* cos(24*pi*x1 + (4*j1*pi)/n) + 0.6*x1) .* cos(6*pi*x1 + (j1*pi)/n);

    % For j in J2 (even)
    j2 = j(j2_idx);
    yj(:, j2_idx) = x(:, j2) - (0.3*x1.^2 .* cos(24*pi*x1 + (4*j2*pi)/n) + 0.6*x1) .* sin(6*pi*x1 + (j2*pi)/n);

    scores = zeros(m, 2);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * sum(yj(:, j1_idx).^2, 2);
    scores(:, 2) = 1 - sqrt(x1) + (2/sum(j2_idx)) * sum(yj(:, j2_idx).^2, 2);
end
