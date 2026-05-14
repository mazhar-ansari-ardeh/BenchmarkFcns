function fptr = wrap_cec(name, n, o_vec, sh_rate_override)
    % WRAP_CEC Wrap base functions with CEC scaling and offsets.

    if nargin < 4
        sh_rate_override = -1.0;
    end

    sh_rate = 1.0;
    offset = 0.0;

    switch name
        case 'rosenbrock', sh_rate = 2.048/100.0; offset = 1.0;
        case {'rastrigin', 'rastrigin_noncont'}, sh_rate = 5.12/100.0;
        case 'griewank', sh_rate = 600.0/100.0;
        case 'schwefel', fptr = @(x) schwefel_cecfcn(x); return;
        case 'weierstrass', sh_rate = 0.5/100.0;
        case 'katsuura', sh_rate = 5.0/100.0;
        case 'happycat', sh_rate = 5.0/100.0; offset = -1.0;
        case 'hgbat', sh_rate = 5.0/100.0; offset = -1.0;
        case 'f8f2', sh_rate = 5.0/100.0; offset = 1.0;
        case 'lunacekbirastrigin'
            fptr = @(x) lunacek_wrapper(x, n, o_vec);
            return;
    end

    if sh_rate_override > 0
        sh_rate = sh_rate_override;
    end

    base_fcn = str2func([name, 'fcn']);

    if sh_rate == 1.0 && offset == 0.0
        fptr = base_fcn;
    else
        fptr = @(x) base_fcn(x * sh_rate + offset);
    end
end

function scores = lunacek_wrapper(x, n, o_vec)
    mu0 = 2.5;
    d_param = 1.0;
    s = 1.0 - (1.0 / (2.0 * sqrt(n + 20.0) - 8.2));
    mu1 = -sqrt((mu0^2 - d_param) / s);

    z = 0.2 * x;
    if length(o_vec) == n
        for i = 1:n
            if o_vec(i) < 0
                z(:, i) = z(:, i) * -1.0;
            end
        end
    end

    sum_sq_z = sum(z.^2, 2);
    sum_sq_z_mu = sum((z + mu0 - mu1).^2, 2);
    deceptive = min(sum_sq_z, s * sum_sq_z_mu + d_param * n);
    rastrigin = 10.0 * (n - sum(cos(2.0 * pi * z), 2));
    scores = deceptive + rastrigin;
end
