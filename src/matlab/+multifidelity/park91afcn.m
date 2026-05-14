% Computes the value of the multi-fidelity Park91A benchmark function.
% SCORES = PARK91AFCN(X) returns a matrix of size M-by-2.
function scores = park91afcn(x)
    [m, n] = size(x);
    assert(n == 4, 'The Park91A function is defined on a 4D space.');

    x1 = x(:,1); x2 = x(:,2); x3 = x(:,3); x4 = x(:,4);

    f_hf = (x1 / 2.0) .* (sqrt(1 + (x2 + x3.^2) .* x4 ./ x1.^2) - 1) + ...
           (x1 + 3 * x4) .* exp(1 + sin(x3));
    f_lf = (1 + sin(x1) / 10) .* f_hf - 2 * x1.^2 + x2.^2 + x3.^2 + 0.5;

    scores = [f_hf, f_lf];
end
