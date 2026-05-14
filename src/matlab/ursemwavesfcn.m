% Computes the value of the Ursem Waves benchmark function.
% SCORES = URSEMWAVESFCN(X) computes the value of the function at point X.
% URSEMWAVESFCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = ursemwavesfcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Ursem Waves function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    term1 = -(0.3 * x1).^3;
    term2 = -3.5 * x1 .* x2.^3;
    term3 = 4.7 * cos(3.0 * x1 - x2.^2 .* (2.0 + x1)) .* sin(2.5 * pi * x1);

    scores = term1 + term2 + term3;
end
