% Computes the value of the Table (Holder Table 1) benchmark function.
% SCORES = TABLEFCN(X) computes the value of the function at point X.
% TABLEFCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = tablefcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Table function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = -abs(cos(x1) .* cos(x2) .* exp(abs(1.0 - sqrt(x1.^2 + x2.^2) / pi)));
end
