% Computes the value of the multi-fidelity Heterogeneous (Mainini) benchmark function.
% SCORES = HETEROGENEOUSFCN(X) returns a matrix of size M-by-2.
function scores = heterogeneousfcn(x)
    [m, n] = size(x);
    assert(n == 1, 'The Heterogeneous function is defined on a 1D space.');

    f_lf = sin(30.0 * (x - 0.9).^4) .* cos(2.0 * (x - 0.9)) + (x - 0.9) / 2.0;
    f_hf = (f_lf - 1.0 + x) ./ (1.0 + 0.25 * x);

    scores = [f_hf, f_lf];
end
