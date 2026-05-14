% Computes the value of the OKA1 multi-objective benchmark function.
function scores = oka1fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The OKA1 function only accepts 2D inputs.');

    theta = pi / 12.0;
    x1 = x(:, 1);
    x2 = x(:, 2);

    x1_prime = x1 * cos(theta) - x2 * sin(theta);
    x2_prime = x1 * sin(theta) + x2 * cos(theta);

    f1 = x1_prime;
    f2 = sqrt(2*pi) - sqrt(abs(x1_prime)) + 2.0 * abs(x2_prime - 3.0 * cos(x1_prime) - 3.0).^(1/3);

    scores = [f1, f2];
end
