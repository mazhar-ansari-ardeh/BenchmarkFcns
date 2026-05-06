function scores = damavandifcn(x)
% Computes the value of Damavandi benchmark function.
% SCORES = DAMAVANDIFCN(X) computes the value of the function at point X.
% DAMAVANDIFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    num = sin(pi * (x1 - 2)) .* sin(pi * (x2 - 2));
    den = pi^2 * (x1 - 2) .* (x2 - 2);

    ratio = num ./ den;
    ratio(abs(den) < 1e-12) = 1;

    scores = (1 - abs(ratio).^5) .* (2 + (x1 - 7).^2 + 2 * (x2 - 7).^2);
end
