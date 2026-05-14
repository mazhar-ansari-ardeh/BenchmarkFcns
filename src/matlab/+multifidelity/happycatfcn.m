function scores = happycatfcn(x)
% Computes the value of the multi-fidelity Happy Cat benchmark function.
% SCORES = HAPPYCATFCN(X) computes the value of the multi-fidelity
% Happy Cat function at point X. HAPPYCATFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    x2 = sum(x.^2, 2);
    sx = sum(x, 2);
    hf = ((x2 - n).^2).^0.5 + (0.5 * x2 + sx) / n + 0.5;

    % LF: perturbed parameters
    lf = ((x2 - n).^2).^0.4 + (0.4 * x2 + sx) / n + 0.5;

    scores = [hf, lf];
end
