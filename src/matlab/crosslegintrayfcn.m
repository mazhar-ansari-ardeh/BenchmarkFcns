function scores = crosslegintrayfcn(x)
% Computes the value of Cross-Leg-in-Tray (Cross-Leg-Table) benchmark function.
% SCORES = CROSSLEGINTRAYFCN(X) computes the value of the function at point X.
% CROSSLEGINTRAYFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    expcomponent = abs(100 - (sqrt(x1.^2 + x2.^2) / pi));
    scores = -(abs(sin(x1) .* sin(x2) .* exp(expcomponent)) + 1).^-0.1;
end
