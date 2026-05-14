function scores = ellipticfcn(x)
% Computes the value of the multi-fidelity Elliptic benchmark function.
% SCORES = ELLIPTICFCN(X) computes the value of the multi-fidelity
% Elliptic function at point X. ELLIPTICFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    coeffs = 10.^(6 * (0:n-1) / (n - 1));
    hf = sum(coeffs .* x.^2, 2);

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
