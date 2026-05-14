% Oscillatory Transformation (T_osz) used in CEC benchmark functions.
function res = t_oszfcn(x)
    res = x;
    [m, n] = size(x);
    for j = 1:n
        col = x(:, j);
        hat_x = zeros(m, 1);
        idx = col ~= 0;
        hat_x(idx) = log(abs(col(idx)));

        c1 = ones(m, 1) * 5.5;
        c1(col > 0) = 10.0;
        c2 = ones(m, 1) * 3.1;
        c2(col > 0) = 7.9;

        res(idx, j) = sign(col(idx)) .* exp(hat_x(idx) + 0.049 * (sin(c1(idx) .* hat_x(idx)) + sin(c2(idx) .* hat_x(idx))));
    end
end
