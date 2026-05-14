function scores = pathologicalfcn(x)
% Computes the value of the Pathological function.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:n-1
        xi = x(:, i);
        xj = x(:, i+1);
        num = sin(sqrt(100*xi.^2 + xj.^2)).^2 - 0.5;
        den = 1 + 0.001*(xi.^2 - 2*xi.*xj + xj.^2).^2;
        scores = scores + 0.5 + num./den;
    end
end
