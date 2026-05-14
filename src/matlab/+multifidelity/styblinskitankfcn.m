function scores = styblinskitankfcn(x)
% Computes the value of the multi-fidelity Styblinski-Tank benchmark function.
% SCORES = STYBLINSKITANKFCN(X) computes the value of the multi-fidelity
% Styblinski-Tank function at point X. STYBLINSKITANKFCN accepts a
% matrix of size M-by-N and returns a matrix SCORES of size M-by-2 in
% which each row contains the high-fidelity (HF) and low-fidelity (LF)
% function values.
%
% Author: Mazhar Ansari Ardeh
    hf = 0.5 * sum(x.^4 - 16 * x.^2 + 5 * x, 2);

    % LF: perturbed parameters
    lf = 0.4 * sum(x.^4 - 14 * x.^2 + 4 * x, 2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
