function scores = jennrichsampsonfcn(x)
% Computes the value of Jennrich-Sampson benchmark function.
% SCORES = JENNRICHSAMPSONFCN(X) computes the value of the function at point X.
% JENNRICHSAMPSONFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:10
        scores = scores + (exp(i * x1) + exp(i * x2) - (2 + 2 * i)).^2;
    end
end
