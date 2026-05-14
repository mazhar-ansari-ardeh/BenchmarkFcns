function scores = levyfcn(x)
% Computes the value of the multi-fidelity Levy benchmark function.
% SCORES = LEVYFCN(X) computes the value of the multi-fidelity Levy
% function at point X. LEVYFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    w = 1 + (x - 1) / 4;
    hf = sin(pi * w(:, 1)).^2 + (w(:, n) - 1).^2 .* (1 + sin(2 * pi * w(:, n)).^2);
    if n > 1
        hf = hf + sum((w(:, 1:n-1) - 1).^2 .* (1 + 10 * sin(pi * w(:, 1:n-1) + 1).^2), 2);
    end

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
