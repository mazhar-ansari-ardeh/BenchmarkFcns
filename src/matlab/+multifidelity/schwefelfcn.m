function scores = schwefelfcn(x)
% Computes the value of the multi-fidelity Schwefel benchmark function.
% SCORES = SCHWEFELFCN(X) computes the value of the multi-fidelity
% Schwefel function at point X. SCHWEFELFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    hf = 418.9829 * n - sum(x .* sin(sqrt(abs(x))), 2);

    % LF
    lf = 380.0 * n - 0.8 * sum(x .* sin(sqrt(abs(x))), 2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
