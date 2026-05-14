function scores = mishran5fcn(x)
% Computes the value of Mishra's Function No. 5 benchmark function.
% SCORES = MISHRAN5FCN(X) computes the value of the function at point X.
% MISHRAN5FCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    term1 = (cos(x1) + cos(x2)).^2;
    term2 = (sin(x1) + sin(x2)).^2;

    scores = (sin(term1).^2 + cos(term2).^2 + x1).^2 + 0.01*x1 + 0.1*x2;
end
