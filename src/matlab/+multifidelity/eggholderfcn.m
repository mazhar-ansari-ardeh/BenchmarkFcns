function scores = eggholderfcn(x)
% Computes the value of the multi-fidelity Eggholder benchmark function.
% SCORES = EGGHOLDERFCN(X) computes the value of the multi-fidelity
% Eggholder function at point X. EGGHOLDERFCN accepts a matrix of size
% M-by-2 and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Eggholder function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    hf = -(Y + 47) .* sin(sqrt(abs(X/2 + (Y + 47)))) - X .* sin(sqrt(abs(X - (Y + 47))));

    % LF
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
