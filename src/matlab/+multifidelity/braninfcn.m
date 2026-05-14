% Computes the value of the multi-fidelity Branin benchmark function.
% SCORES = BRANINFCN(X) returns a matrix of size M-by-2.
function scores = braninfcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Branin function is defined on a 2D space.');

    x1 = x(:,1); x2 = x(:,2);

    branin_hf = @(x1, x2) (x2 - (5.1 ./ (4 * pi^2)) * x1.^2 + (5 / pi) * x1 - 6).^2 + 10 * (1 - 1 / (8 * pi)) * cos(x1) + 10;

    f_hf = branin_hf(x1, x2);
    % Toal adjustable version or typical MF extension
    f_lf = 10.0 * branin_hf(1.2 * x1, 1.2 * x2) + 5.0 * x1 + 10.0 * x2;

    scores = [f_hf, f_lf];
end
