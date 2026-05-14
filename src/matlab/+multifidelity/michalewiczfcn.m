function scores = michalewiczfcn(x)
% Computes the value of the multi-fidelity Michalewicz benchmark function.
% SCORES = MICHALEWICZFCN(X) computes the value of the multi-fidelity
% Michalewicz function at point X. MICHALEWICZFCN accepts a matrix of
% size M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    i = 1:n;
    hf = -sum(sin(x) .* (sin(i .* x.^2 / pi)).^20, 2);

    % LF: perturbed parameters
    lf = -0.5 * sum(sin(x) .* (sin(i .* x.^2 / pi)).^10, 2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
