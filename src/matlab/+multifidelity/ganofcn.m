% Computes the value of the multi-fidelity Gano benchmark function.
% SCORES = GANOFCN(X, RETURN_CONSTRAINTS) returns a matrix of size M-by-4.
function scores = ganofcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Gano function is defined on a 2D space.');

    x1 = x(:,1); x2 = x(:,2);

    f_hf = 4.0 * x1.^2 + x2.^3 + x1 .* x2;
    g_hf = 1.0 ./ x1 + 1.0 ./ x2 - 2.0;

    f_lf = 4.0 * (x1 + 0.1).^2 + (x2 - 0.1).^3 + x1 .* x2 + 0.1;
    g_lf = 1.0 ./ x1 + 1.0 ./ (x2 + 0.1) - 2.0 - 0.001;

    scores = [f_hf, g_hf, f_lf, g_lf];
end
