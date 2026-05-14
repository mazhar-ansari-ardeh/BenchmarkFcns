% Computes the value of the multi-fidelity Currin benchmark function.
% SCORES = CURRINFCN(X) returns a matrix of size M-by-2.
function scores = currinfcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Currin function is defined on a 2D space.');

    x1 = x(:,1); x2 = x(:,2);

    currin_hf = @(x1, x2) (1.0 - exp(-1.0 ./ (2.0 * x2))) .* ...
                          (2300 * x1.^3 + 1900 * x1.^2 + 2092 * x1 + 60) ./ ...
                          (100 * x1.^3 + 500 * x1.^2 + 4 * x1 + 20);

    f_hf = currin_hf(x1, x2);
    f_lf = 0.25 * (currin_hf(x1 + 0.05, x2 + 0.05) + ...
                   currin_hf(x1 + 0.05, max(0, x2 - 0.05)) + ...
                   currin_hf(max(0, x1 - 0.05), x2 + 0.05) + ...
                   currin_hf(max(0, x1 - 0.05), max(0, x2 - 0.05)));

    scores = [f_hf, f_lf];
end
