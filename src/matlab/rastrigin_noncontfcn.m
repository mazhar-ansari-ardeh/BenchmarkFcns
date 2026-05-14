% Computes the value of the Non-continuous Rastrigin benchmark function.
% SCORES = RASTRIGIN_NONCONTFCN(X) computes the value of the
% Non-continuous Rastrigin function at point X.
%
% Author: Mazhar Ansari Ardeh
function scores = rastrigin_noncontfcn(x)
    [m, n] = size(x);
    y = x;
    mask = abs(x) > 0.5;
    y(mask) = floor(2 * x(mask) + 0.5) / 2;

    scores = sum(y.^2, 2) + 10 * n - 10 * sum(cos(2 * pi * y), 2);
end
