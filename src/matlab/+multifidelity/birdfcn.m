function scores = birdfcn(x)
% Computes the value of the multi-fidelity Bird benchmark function.
% SCORES = BIRDFCN(X) computes the value of the multi-fidelity Bird
% function at point X. BIRDFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    if size(x, 2) ~= 2
        error('The multi-fidelity Bird function is only defined on a 2D space.');
    end
    X = x(:, 1);
    Y = x(:, 2);
    hf = sin(X) .* exp((1 - cos(Y)).^2) + cos(Y) .* exp((1 - sin(X)).^2) + (X - Y).^2;

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
