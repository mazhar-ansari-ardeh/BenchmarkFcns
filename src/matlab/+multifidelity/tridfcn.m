function scores = tridfcn(x)
% Computes the value of the multi-fidelity Trid benchmark function.
% SCORES = TRIDFCN(X) computes the value of the multi-fidelity Trid
% function at point X. TRIDFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    hf = sum((x - 1).^2, 2);
    if n > 1
        hf = hf - sum(x(:, 2:end) .* x(:, 1:end-1), 2);
    end

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
