function scores = zakharovfcn(x)
% Computes the value of the multi-fidelity Zakharov benchmark function.
% SCORES = ZAKHAROVFCN(X) computes the value of the multi-fidelity Zakharov
% function at point X. ZAKHAROVFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    s1 = sum(x .^ 2, 2);

    i_vec = 1:n;
    s2 = sum(0.5 * i_vec .* x, 2);

    hf = s1 + s2 .^ 2 + s2 .^ 4;

    % LF: perturbed parameters
    lf = 0.5 * s1 + s2 .^ 2 + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
