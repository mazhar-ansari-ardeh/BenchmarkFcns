function scores = bentcigarfcn(x)
% Computes the value of the multi-fidelity Bent Cigar benchmark function.
% SCORES = BENTCIGARFCN(X) computes the value of the multi-fidelity
% Bent Cigar function at point X. BENTCIGARFCN accepts a matrix of
% size M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    x1_sq = x(:, 1).^2;
    if n > 1
        x_rest_sq = sum(x(:, 2:end).^2, 2);
    else
        x_rest_sq = 0;
    end
    hf = x1_sq + 1e6 * x_rest_sq;

    % LF: perturbed parameters
    lf = x1_sq + 1e5 * x_rest_sq + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
