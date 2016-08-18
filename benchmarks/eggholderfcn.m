function scores = eggholderfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Eggholder function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);
    
    sin1component = sin(sqrt(abs( (X / 2) + Y + 47)));
    sin2component = sin(sqrt(abs( X - Y + 47)));
    
    scores = -(Y + 47) .* sin1component - (X .* sin2component);
end