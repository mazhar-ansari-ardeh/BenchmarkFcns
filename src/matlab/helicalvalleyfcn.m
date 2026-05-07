function scores = helicalvalleyfcn(x)
% Computes the value of Helical Valley benchmark function.
% SCORES = HELICALVALLEYFCN(X) computes the value of the function at point X.
% HELICALVALLEYFCN accepts a matrix of size M-by-3 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);

    theta = (0.5 / pi) * atan2(x2, x1);
    scores = 100 * ((x3 - 10 * theta).^2 + (sqrt(x1.^2 + x2.^2) - 1).^2) + x3.^2;
end
