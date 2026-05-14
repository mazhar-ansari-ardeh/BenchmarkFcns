function scores = penholderfcn(x)
% Computes the value of the Pen Holder function.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    inner = abs(cos(x1).*cos(x2).*exp(abs(1 - sqrt(x1.^2 + x2.^2)/pi)));
    scores = -exp(-inner.^-1);
end
