function scores = spherefcn(x)
% Computes the value of the multi-fidelity Sphere benchmark function.
% SCORES = SPHEREFCN(X) computes the value of the multi-fidelity
% Sphere function at point X. SPHEREFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    hf = sum(x .^ 2, 2);

    % LF
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
