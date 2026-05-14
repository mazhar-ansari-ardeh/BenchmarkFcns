function scores = mishran6fcn(x)
% Computes the value of Mishra's Function No. 6 benchmark function.
% SCORES = MISHRAN6FCN(X) computes the value of the function at point X.
% MISHRAN6FCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    g1 = sin((cos(x1) + cos(x2)).^2).^2;
    g2 = cos((sin(x1) + sin(x2)).^2).^2;

    inner = (g1 - g2 + x1).^2;

    scores = -log(inner + 1e-15) + 0.1 * ((x1 - 1).^2 + (x2 - 1).^2);
end
