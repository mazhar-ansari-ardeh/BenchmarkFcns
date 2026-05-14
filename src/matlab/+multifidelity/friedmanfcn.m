% Computes the value of the multi-fidelity Friedman benchmark function.
% SCORES = FRIEDMANFCN(X) returns a matrix of size M-by-2.
function scores = friedmanfcn(x)
    [m, n] = size(x);
    assert(n == 5, 'The Friedman function is defined on a 5D space.');

    x1 = x(:,1); x2 = x(:,2); x3 = x(:,3); x4 = x(:,4); x5 = x(:,5);

    common = 10 * sin(pi * x1 .* x2) + 20 * (x3 - 0.5).^2;
    f_hf = common + 10 * x4 + 5 * x5;
    f_lf = common + 5 * x4 + 2.5 * x5;

    scores = [f_hf, f_lf];
end
