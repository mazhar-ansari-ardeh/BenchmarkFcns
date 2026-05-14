function scores = ackleyfcn(x)
% Computes the value of the multi-fidelity Ackley benchmark function.
% SCORES = ACKLEYFCN(X) computes the value of the multi-fidelity Ackley
% function at point X. ACKLEYFCN accepts a matrix of size M-by-N and
% returns a matrix SCORES of size M-by-2 in which each row contains
% the high-fidelity (HF) and low-fidelity (LF) function values.
%
% Author: Mazhar Ansari Ardeh
    n = size(x, 2);
    ninverse = 1 / n;
    sum1 = sum(x .^ 2, 2);
    sum2 = sum(cos(2 * pi * x), 2);

    hf = 20 + exp(1) - (20 * exp(-0.2 * sqrt( ninverse * sum1))) - exp( ninverse * sum2);

    % LF: perturbed parameters
    lf = 18 + exp(1) - (18 * exp(-0.18 * sqrt( ninverse * sum1))) - exp( ninverse * sum2) + 0.1 * sum(x, 2);

    scores = [hf, lf];
end
