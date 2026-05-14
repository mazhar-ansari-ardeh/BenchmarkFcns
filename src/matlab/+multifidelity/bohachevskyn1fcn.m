function scores = bohachevskyn1fcn(x)
% Computes the value of the multi-fidelity Bohachevsky N. 1 benchmark function.
% SCORES = BOHACHEVSKYN1FCN(X) computes the value of the multi-fidelity
% Bohachevsky N. 1 function at point X. BOHACHEVSKYN1FCN accepts a matrix
% of size M-by-2 and returns a matrix SCORES of size M-by-2 in which each
% row contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Bohachevsky N. 1 function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    hf = X.^2 + 2*Y.^2 - 0.3*cos(3*pi*X) - 0.4*cos(4*pi*Y) + 0.7;

    % LF
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
