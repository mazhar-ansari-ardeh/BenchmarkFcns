function scores = bealefcn(x)
% Computes the value of the multi-fidelity Beale benchmark function.
% SCORES = BEALEFCN(X) computes the value of the multi-fidelity Beale
% function at point X. BEALEFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    if size(x, 2) ~= 2
        error('The multi-fidelity Beale function is only defined on a 2D space.');
    end
    X = x(:, 1);
    Y = x(:, 2);
    hf = (1.5 - X + (X .* Y)).^2 + (2.25 - X + (X .* Y.^2)).^2 + (2.625 - X + (X .* Y.^3)).^2;

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
