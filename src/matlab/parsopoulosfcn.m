function scores = parsopoulosfcn(x)
% Computes the value of the Parsopoulos function.
%
% Author: Mazhar Ansari Ardeh
    scores = cos(x(:, 1)).^2 + sin(x(:, 2)).^2;
end
