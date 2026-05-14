function scores = mishran3fcn(x)
% Computes the value of Mishra's Function No. 3 benchmark function.
% SCORES = MISHRAN3FCN(X) computes the value of the function at point X.
% MISHRAN3FCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = sqrt(abs(cos(sqrt(abs(x1.^2 + x2))))) + 0.01 * (x1 + x2);
end
