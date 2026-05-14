% Computes the value of the multi-fidelity Xiong 1D benchmark function.
% SCORES = XIONG1DFCN(X) returns a matrix of size M-by-2.
function scores = xiong1dfcn(x)
    [m, n] = size(x);
    assert(n == 1, 'The Xiong 1D function is defined on a 1D space.');

    f_hf = sin(30.0 * (x - 0.9).^4) .* cos(2.0 * (x - 0.9)) + (x - 0.9) / 2.0;
    f_lf = 0.5 * f_hf + 10.0 * (x - 0.5);

    scores = [f_hf, f_lf];
end
