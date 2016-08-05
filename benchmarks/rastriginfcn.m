function f = rastriginfcn(x)
    n = size(x, 2);
    A = 10;
    f = (A * n) + (sum(x .^2 - A * cos(2 * pi * x), 2));
end