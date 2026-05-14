function scores = pinterfcn(x)
% Computes the value of the Pinter benchmark function.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:n
        prev = i - 1; if prev == 0, prev = n; end
        next = i + 1; if next > n, next = 1; end

        xi = x(:, i);
        x_prev = x(:, prev);
        x_next = x(:, next);

        Ai = x_prev.*sin(xi) + sin(x_next);
        Bi = x_prev.^2 - 2*xi + 3*x_next - cos(xi) + 1;

        scores = scores + i * (xi.^2 + 20*Ai.^2 + log10(1 + i*Bi.^2));
    end
end
