function scores = boxbettsfcn(x)
% Computes the value of Box-Betts Quadratic Sum benchmark function.
% SCORES = BOXBETTSFCN(X) computes the value of the function at point X.
% BOXBETTSFCN accepts a matrix of size M-by-3 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:10
        coeff = 0.1 * (i + 1);
        term = exp(-coeff * x1) - exp(-coeff * x2) - (exp(-coeff) - exp(-(i + 1))) * x3;
        scores = scores + term.^2;
    end
end
