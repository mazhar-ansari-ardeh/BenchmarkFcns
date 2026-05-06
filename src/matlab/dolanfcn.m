function scores = dolanfcn(x)
% Computes the value of Dolan benchmark function.
% SCORES = DOLANFCN(X) computes the value of the function at point X.
% DOLANFCN accepts a matrix of size M-by-5 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);
    x5 = x(:, 5);

    scores = (x1 + 1.7 * x2) .* sin(x1) - 1.5 * x3 - 0.1 * x4 .* cos(x4 + x5 - x1) + ...
             0.2 * x2.^5 - x2 - 1.0;
end
