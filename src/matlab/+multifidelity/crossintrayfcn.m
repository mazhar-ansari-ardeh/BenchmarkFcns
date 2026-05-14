function scores = crossintrayfcn(x)
% Computes the value of the multi-fidelity Cross-in-tray benchmark function.
% SCORES = CROSSINTRAYFCN(X) computes the value of the multi-fidelity
% Cross-in-tray function at point X. CROSSINTRAYFCN accepts a matrix of
% size M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    if size(x, 2) ~= 2
        error('The multi-fidelity Cross-in-tray function is only defined on a 2D space.');
    end
    X = x(:, 1);
    Y = x(:, 2);
    expcomponent = abs(100 - (sqrt(X.^2 + Y.^2) / pi));
    hf = -0.0001 * (abs(sin(X) .* sin(Y) .* exp(expcomponent)) + 1).^0.1;

    % LF: perturbed parameters
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
