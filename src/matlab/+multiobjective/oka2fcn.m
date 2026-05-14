% Computes the value of the OKA2 multi-objective benchmark function.
function scores = oka2fcn(x)
    [m, n] = size(x);
    assert(n == 3, 'The OKA2 function only accepts 3D inputs.');

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);

    f1 = x1;
    f2 = 1.0 - (1.0 / (4.0 * pi^2)) * (x1 + pi).^2 + ...
         abs(x2 - 5.0 * cos(x1)).^(1/3) + ...
         abs(x3 - 5.0 * sin(x1)).^(1/3);

    scores = [f1, f2];
end
