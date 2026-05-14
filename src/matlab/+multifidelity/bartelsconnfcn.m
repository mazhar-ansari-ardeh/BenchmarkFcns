function scores = bartelsconnfcn(x)
% Computes the value of the multi-fidelity Bartels Conn benchmark function.
% SCORES = BARTELSCONNFCN(X) computes the value of the multi-fidelity
% Bartels Conn function at point X. BARTELSCONNFCN accepts a matrix of
% size M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    if size(x, 2) ~= 2
        error('The multi-fidelity Bartels Conn function is only defined on a 2D space.');
    end
    X = x(:, 1);
    Y = x(:, 2);
    hf = abs(X.^2 + Y.^2 + X .* Y) + abs(sin(X)) + abs(cos(Y));

    % LF: perturbed parameters
    lf = 0.7 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
