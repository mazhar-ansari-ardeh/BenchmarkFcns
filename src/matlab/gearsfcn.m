% Computes the value of the Gear Train Design benchmark function.
% SCORES = GEARFCN(X) computes the value of the Gear Train Design function at
% point X. GEARFCN accepts a matrix of size M-by-4 and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% the corresponding row of X.
function scores = gearfcn(x)
    n = size(x, 2);
    assert(n == 4, 'The Gear function is only defined on a 4D space.')

    target = 1.0 / 6.931;

    x1 = floor(x(:, 1));
    x2 = floor(x(:, 2));
    x3 = floor(x(:, 3));
    x4 = floor(x(:, 4));

    actual_ratio = (x1 .* x2) ./ (x3 .* x4);

    scores = (target - actual_ratio).^2;
end
