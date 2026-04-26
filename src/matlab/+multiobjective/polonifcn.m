% Computes the value of the Poloni multi-objective benchmark function.
% SCORES = POLONIFCN(X) computes the value of the Poloni function
% at point X. POLONIFCN accepts a matrix of size M-by-2 and returns
% a matrix SCORES of size M-by-2.
function scores = polonifcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Poloni function is only defined on a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 2);
    x1 = x(:, 1);
    x2 = x(:, 2);

    A1 = 0.5 * sin(1) - 2 * cos(1) + sin(2) - 1.5 * cos(2);
    A2 = 1.5 * sin(1) - cos(1) + 2 * sin(2) - 0.5 * cos(2);

    B1 = 0.5 * sin(x1) - 2 * cos(x1) + sin(x2) - 1.5 * cos(x2);
    B2 = 1.5 * sin(x1) - cos(x1) + 2 * sin(x2) - 0.5 * cos(x2);

    scores(:, 1) = 1 + (A1 - B1).^2 + (A2 - B2).^2;
    scores(:, 2) = (x1 + 3).^2 + (x2 + 1).^2;
end
