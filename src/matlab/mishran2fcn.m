function scores = mishran2fcn(x)
% Computes the value of Mishra's Function No. 2 benchmark function.
% SCORES = MISHRAN2FCN(X) computes the value of the function at point X.
% MISHRAN2FCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);

    gn = n - sum(0.5 * (x(:, 1:n-1) + x(:, 2:n)), 2);

    scores = (1 + gn).^gn;
end
