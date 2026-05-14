% Computes the value of the Test Tube Holder benchmark function.
% SCORES = TESTTUBEHOLDERFCN(X) computes the value of the function at point X.
% TESTTUBEHOLDERFCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
function scores = testtubeholderfcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Test Tube Holder function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    scores = -4.0 * abs(sin(x1) .* cos(x2) .* exp(abs(cos((x1.^2 + x2.^2) / 200.0))));
end
