function scores = mishran7fcn(x)
% Computes the value of Mishra's Function No. 7 benchmark function.
% SCORES = MISHRAN7FCN(X) computes the value of the function at point X.
% MISHRAN7FCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);

    fact_n = factorial(n);

    scores = (prod(x, 2) - fact_n).^2;
end
