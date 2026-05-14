function scores = himmelblaufcn(x)
% Computes the value of the multi-fidelity Himmelblau benchmark function.
% SCORES = HIMMELBLAUFCN(X) computes the value of the multi-fidelity
% Himmelblau function at point X. HIMMELBLAUFCN accepts a matrix
% of size M-by-2 and returns a matrix SCORES of size M-by-2 in which each
% row contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Himmelblau function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    hf = (X.^2 + Y - 11).^2 + (X + Y.^2 - 7).^2;

    % LF
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
