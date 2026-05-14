% Computes the value of the CEC 2009 UF3 multi-objective benchmark function.
function scores = uf3fcn(x)
    [m, n] = size(x);
    x1 = x(:, 1);
    j = 2:n;

    exponent = 0.5 * (1 + 3*(j-2)/(n-2));
    yj = x(:, 2:end) - x1.^exponent;

    j1_idx = mod(j, 2) ~= 0;
    j2_idx = mod(j, 2) == 0;

    yj1 = yj(:, j1_idx);
    yj2 = yj(:, j2_idx);
    j1 = j(j1_idx);
    j2 = j(j2_idx);

    scores = zeros(m, 2);
    scores(:, 1) = x1 + (2/sum(j1_idx)) * (4*sum(yj1.^2, 2) - 2*prod(cos(20*yj1*pi./sqrt(j1)), 2) + 2);
    scores(:, 2) = 1 - sqrt(x1) + (2/sum(j2_idx)) * (4*sum(yj2.^2, 2) - 2*prod(cos(20*yj2*pi./sqrt(j2)), 2) + 2);
end
