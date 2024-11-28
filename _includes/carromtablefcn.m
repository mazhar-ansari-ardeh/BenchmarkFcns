function scores = carromtablefcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Carrom Table function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    s = 1 - ((sqrt(X.^2 + Y.^2)) / pi);
    scores = - (1/30) * exp(2 * abs(s)) .* (cos(X).^2) .* (cos(Y).^2);
