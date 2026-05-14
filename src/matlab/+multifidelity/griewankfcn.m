function scores = griewankfcn(x)
% Computes the value of the multi-fidelity Griewank benchmark function.
% SCORES = GRIEWANKFCN(X) computes the value of the multi-fidelity
% Griewank function at point X. GRIEWANKFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    sum_comp = sum(x.^2 / 4000, 2);
    prod_comp = prod(cos(x ./ sqrt(1:n)), 2);
    hf = sum_comp - prod_comp + 1;

    % LF
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
