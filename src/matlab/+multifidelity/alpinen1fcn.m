function scores = alpinen1fcn(x)
% Computes the value of the multi-fidelity Alpine N. 1 benchmark function.
% SCORES = ALPINEN1FCN(X) computes the value of the multi-fidelity
% Alpine N. 1 function at point X. ALPINEN1FCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    hf = abs(sum(x .* sin(x) + 0.1 * x, 2));

    % LF: perturbed parameters
    lf = 0.5 * abs(sum(x .* sin(x) + 0.2 * x, 2)) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
