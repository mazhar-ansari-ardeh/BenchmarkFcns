function scores = mishran1fcn(x)
% Computes the value of Mishra's Function No. 1 benchmark function.
% SCORES = MISHRAN1FCN(X) computes the value of the function at point X.
% MISHRAN1FCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);

    gn = n - sum(x(:, 1:n-1), 2);

    scores = (1 + gn).^gn;
end
