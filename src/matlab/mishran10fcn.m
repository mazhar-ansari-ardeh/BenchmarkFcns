function scores = mishran10fcn(x)
% Computes the value of Mishra's Function No. 10 benchmark function.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores = (floor(x1 + x2) - floor(x1) - floor(x2)).^2;
end
