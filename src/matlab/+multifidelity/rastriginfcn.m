function scores = rastriginfcn(x)
% Computes the value of the multi-fidelity Rastrigin benchmark function.
% SCORES = RASTRIGINFCN(X) computes the value of the multi-fidelity
% Rastrigin function at point X. RASTRIGINFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    hf = 10 * n + sum(x .^ 2 - 10 * cos(2 * pi * x), 2);

    % LF: perturbed parameters
    lf = 10 * n + sum(x .^ 2 - 8 * cos(2 * pi * x), 2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
