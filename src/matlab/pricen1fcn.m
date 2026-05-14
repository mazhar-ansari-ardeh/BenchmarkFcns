function scores = pricen1fcn(x)
% Computes the value of Price's Function No. 1 benchmark function.
%
% Author: Mazhar Ansari Ardeh
    scores = (abs(x(:, 1)) - 5).^2 + (abs(x(:, 2)) - 5).^2;
end
