function scores = easomfcn(x)
% Computes the value of the multi-fidelity Easom benchmark function.
% SCORES = EASOMFCN(X) computes the value of the multi-fidelity
% Easom function at point X. EASOMFCN accepts a matrix of size
% M-by-2 and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    assert(size(x, 2) == 2, 'The multi-fidelity Easom function is only defined on a 2D space.');
    X = x(:, 1);
    Y = x(:, 2);

    hf = -cos(X) .* cos(Y) .* exp(-((X - pi).^2 + (Y - pi).^2));

    % LF
    lf = 0.5 * hf + 0.1 * (X + Y);

    scores = [hf, lf];
end
