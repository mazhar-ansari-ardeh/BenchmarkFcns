function scores = matyasfcn(x)
% Computes the value of the multi-fidelity Matyas benchmark function.
% SCORES = MATYASFCN(X) computes the value of the multi-fidelity
% Matyas function at point X. MATYASFCN accepts a matrix of size
% M-by-2 and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Matyas function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    hf = 0.26 * (X.^2 + Y.^2) - 0.48 * X .* Y;

    % LF
    lf = 0.28 * (X.^2 + Y.^2) - 0.45 * X .* Y + 0.1 * (X + Y);

    scores = [hf, lf];
end
