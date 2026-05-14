% Computes the value of the multi-fidelity Park91B benchmark function.
% SCORES = PARK91BFCN(X) returns a matrix of size M-by-2.
function scores = park91bfcn(x)
    [m, n] = size(x);
    assert(n == 4, 'The Park91B function is defined on a 4D space.');

    x1 = x(:,1); x2 = x(:,2); x3 = x(:,3); x4 = x(:,4);

    f_hf = 2/3 * exp(x1 + x2) - x4 .* sin(x3) + x3;
    f_lf = 1.2 * f_hf - 1.0;

    scores = [f_hf, f_lf];
end
