% Asymmetric Transformation (T_asy) used in CEC benchmark functions.
function res = t_asyfcn(x, beta)
    if nargin < 2, beta = 0.2; end
    [m, n] = size(x);
    res = x;
    if n <= 1
        return;
    end
    for j = 1:n
        col = x(:, j);
        exponent = 1.0 + beta * ((j-1) / (n - 1)) * sqrt(abs(col));
        mask = col > 0;
        res(mask, j) = col(mask) .^ exponent(mask);
    end
end
