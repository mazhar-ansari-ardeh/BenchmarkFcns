function fptr = wrap_cec(name, n, o_vec)
    % WRAP_CEC Wrap base functions with CEC scaling and offsets.

    if nargin < 3
        o_vec = [];
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
    end

    base_fcn = str2func([name, 'fcn']);

    if sh_rate == 1.0 && offset == 0.0
        fptr = base_fcn;
    else
        fptr = @(x) base_fcn(x * sh_rate + offset);
    end
end
