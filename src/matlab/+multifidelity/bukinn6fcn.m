function scores = bukinn6fcn(x)
% Computes the value of the multi-fidelity Bukin N. 6 benchmark function.
% SCORES = BUKINN6FCN(X) computes the value of the multi-fidelity
% Bukin N. 6 function at point X. BUKINN6FCN accepts a matrix of size
% M-by-N and returns a matrix SCORES of size M-by-2 in which each row
% contains the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    if size(x, 2) ~= 2
        error('The multi-fidelity Bukin N. 6 function is only defined on a 2D space.');
    end
    X = x(:, 1);
    Y = x(:, 2);
    hf = 100 * sqrt(abs(Y - 0.01 * X.^2)) + 0.01 * abs(X + 10);

    % LF: perturbed parameters
    lf = 80 * sqrt(abs(Y - 0.01 * X.^2)) + 0.02 * abs(X + 10) + 0.1 * X;

    scores = [hf, lf];
end
