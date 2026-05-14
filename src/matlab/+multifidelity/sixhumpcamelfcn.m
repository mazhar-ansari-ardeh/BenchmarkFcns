function scores = sixhumpcamelfcn(x)
% Computes the value of the multi-fidelity Six-hump Camel benchmark function.
% SCORES = SIXHUMPCAMELFCN(X) computes the value of the multi-fidelity
% Six-hump Camel function at point X. SIXHUMPCAMELFCN accepts a matrix
% of size M-by-2 and returns a matrix SCORES of size M-by-2 in which each
% row contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Six-hump Camel function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    hf = (4 - 2.1 * X.^2 + X.^4 / 3) .* X.^2 + X .* Y + (-4 + 4 * Y.^2) .* Y.^2;

    % LF: perturbed parameters
    lf = (3.5 - 2.0 * X.^2 + X.^4 / 4) .* X.^2 + X .* Y + (-3.5 + 3.5 * Y.^2) .* Y.^2;

    scores = [hf, lf];
end
