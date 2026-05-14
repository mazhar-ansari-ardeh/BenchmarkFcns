function scores = pavianifcn(x)
% Computes the value of the Paviani function.
%
% Author: Mazhar Ansari Ardeh
    scores = sum(log(x - 2).^2 + log(10 - x).^2, 2) - prod(x, 2).^0.2;
end
