function scores = engvallfcn(x)
% Computes the value of Engvall benchmark function.
% SCORES = ENGVALLFCN(X) computes the value of the function at point X.
% ENGVALLFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = x1.^4 + x2.^4 + 2 * x1.^2 .* x2.^2 - 4 * x1 + 3.0;
end
