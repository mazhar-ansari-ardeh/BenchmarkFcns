function scores = goldsteinpricefcn(x)
% Computes the value of the multi-fidelity Goldstein-Price benchmark function.
% SCORES = GOLDSTEINPRICEFCN(X) computes the value of the multi-fidelity
% Goldstein-Price function at point X. GOLDSTEINPRICEFCN accepts a matrix
% of size M-by-2 and returns a matrix SCORES of size M-by-2 in which each
% row contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Goldstein-Price function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    term1 = 1 + (X + Y + 1).^2 .* (19 - 14*X + 3*X.^2 - 14*Y + 6*X.*Y + 3*Y.^2);
    term2 = 30 + (2*X - 3*Y).^2 .* (18 - 32*X + 12*X.^2 + 48*Y - 36*X.*Y + 27*Y.^2);
    hf = term1 .* term2;

    % LF
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
