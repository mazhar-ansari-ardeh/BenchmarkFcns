function scores = brownfcn(x)
% Computes the value of the multi-fidelity Brown benchmark function.
% SCORES = BROWNFCN(X) computes the value of the multi-fidelity Brown
% function at point X. BROWNFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    hf = zeros(m, 1);
    for i = 1:n-1
        xi = x(:, i);
        xi_next = x(:, i+1);
        hf = hf + (xi.^2).^(xi_next.^2 + 1) + (xi_next.^2).^(xi.^2 + 1);
    end

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
