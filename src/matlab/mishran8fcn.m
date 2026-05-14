function scores = mishran8fcn(x)
% Computes the value of Mishra's Function No. 8 benchmark function.
% SCORES = MISHRAN8FCN(X) computes the value of the function at point X.
% MISHRAN8FCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    g = (x1 - 2).^10;
    h = (x2 + 3).^4;

    scores = 0.001 * (g + h).^2;
end
