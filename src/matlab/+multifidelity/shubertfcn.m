function scores = shubertfcn(x)
% Computes the value of the multi-fidelity Shubert benchmark function.
% SCORES = SHUBERTFCN(X) computes the value of the multi-fidelity Shubert
% function at point X. SHUBERTFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    col_sums_hf = zeros(m, n);
    col_sums_lf = zeros(m, n);
    for j = 1:5
        col_sums_hf = col_sums_hf + j * cos((j + 1) * x + j);
        col_sums_lf = col_sums_lf + j * cos((j + 1.1) * x + j);
    end
    hf = prod(col_sums_hf, 2);

    % LF: perturbed parameters
    lf = 0.5 * prod(col_sums_lf, 2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
