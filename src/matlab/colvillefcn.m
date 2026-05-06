function scores = colvillefcn(x)
% Computes the value of Colville benchmark function.
% SCORES = COLVILLEFCN(X) computes the value of the function at point X.
% COLVILLEFCN accepts a matrix of size M-by-4 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    scores = 100 * (x1.^2 - x2).^2 + (x1 - 1).^2 + (x3 - 1).^2 + ...
             90 * (x3.^2 - x4).^2 + 10.1 * ((x2 - 1).^2 + (x4 - 1).^2) + ...
             19.8 * (x2 - 1) .* (x4 - 1);
end
