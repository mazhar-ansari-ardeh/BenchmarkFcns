function scores = katsuurafcn(x)
% Computes the value of the multi-fidelity Katsuura benchmark function.
% SCORES = KATSUURAFCN(X) computes the value of the multi-fidelity
% Katsuura function at point X. KATSUURAFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    m = size(x, 1);
    inner_sum = zeros(m, n);
    for j = 1:32
        two_pow_j = 2^j;
        val = two_pow_j * x;
        inner_sum = inner_sum + abs(val - round(val)) / two_pow_j;
    end
    i_vec = 1:n;
    prod_terms = 1 + inner_sum .* i_vec;
    hf = (10 / n^2) * (prod(prod_terms.^(10 / n^1.2), 2) - 1);

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
