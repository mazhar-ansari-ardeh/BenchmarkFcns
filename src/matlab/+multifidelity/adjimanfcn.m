function scores = adjimanfcn(x)
% Computes the value of the multi-fidelity Adjiman benchmark function.
% SCORES = ADJIMANFCN(X) computes the value of the multi-fidelity
% Adjiman function at point X. ADJIMANFCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    if size(x, 2) ~= 2
        error('The multi-fidelity Adjiman function is only defined on a 2D space.');
    end
    X = x(:, 1);
    Y = x(:, 2);
    hf = cos(X) .* sin(Y) - (X ./ (Y.^2 + 1));

    % LF: perturbed parameters
    lf = 0.8 * hf + 0.1 * X + 0.1 * Y;

    scores = [hf, lf];
end
