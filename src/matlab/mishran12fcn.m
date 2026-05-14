function scores = mishran12fcn(x)
% Computes the value of Mishra's Function No. 12 benchmark function.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores = sin(x1).*exp((1-cos(x2)).^2) + cos(x2).*exp((1-sin(x1)).^2) + (x1-x2).^2;
end
