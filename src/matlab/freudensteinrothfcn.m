function scores = freudensteinrothfcn(x)
% Computes the value of Freudenstein-Roth benchmark function.
% SCORES = FREUDENSTEINROTHFCN(X) computes the value of the function at point X.
% FREUDENSTEINROTHFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    term1 = x1 - 13.0 + ((5.0 - x2) .* x2 - 2.0) .* x2;
    term2 = x1 - 29.0 + ((x2 + 1.0) .* x2 - 14.0) .* x2;

    scores = term1.^2 + term2.^2;
end
