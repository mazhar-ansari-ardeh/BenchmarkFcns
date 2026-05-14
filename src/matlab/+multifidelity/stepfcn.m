function scores = stepfcn(x)
% Computes the value of the multi-fidelity Step benchmark function.
% SCORES = STEPFCN(X) computes the value of the multi-fidelity Step
% function at point X. STEPFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    hf = sum(floor(x + 0.5).^2, 2);

    % LF: perturbed parameters
    lf = 0.5 * sum(floor(x + 0.6).^2, 2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
