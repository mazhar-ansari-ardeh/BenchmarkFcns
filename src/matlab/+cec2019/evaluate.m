function scores = evaluate(x, fid)
    % EVALUATE Evaluates the CEC 2019 100-Digit Challenge function.

    [m, n] = size(x);

    if fid == 1
        scores = chebyshev(x);
    elseif fid == 2
        scores = hilbert(x);
    elseif fid == 3
        scores = lennard_jones(x);
    else
        [shift_vec, rotation, ~] = cec2019.get_data(fid, n);

        comp = Composition(1.0);
        sh_rate = 1.0;

        switch fid
            case 4, base_name = 'rastrigin'; sh_rate = 5.12/100.0;
            case 5, base_name = 'griewank'; sh_rate = 600.0/100.0;
            case 6, base_name = 'weierstrass'; sh_rate = 0.5/100.0;
            case 7, base_name = 'schwefel'; sh_rate = 1000.0/100.0;
            case 8, base_name = 'schafferf6';
            case 9, base_name = 'happycat'; sh_rate = 5.0/100.0;
            case 10, base_name = 'ackley';
            otherwise, error('CEC 2019 FID must be 1-10.');
        end

        fptr = cec2019.wrap_cec(base_name, n, shift_vec, sh_rate);
        comp.add(fptr, shift_vec, rotation, 1.0, 1.0, 1.0, 1.0);
        scores = comp.evaluate(x);
    end
end

function scores = chebyshev(x)
    [m, n] = size(x);
    num_points = 32 * n;
    dx = 72.66066685442085;

    scores = ones(m, 1);
    for i = 1:m
        p1 = 0; p2 = 0; p3 = 0;

        % p1: P(1.2) >= dx
        u = 0;
        for j = 1:n, u = u * 1.2 + x(i, j); end
        if u < dx, p1 = (u - dx)^2; end

        % p2: P(-1.2) >= dx
        v = 0;
        for j = 1:n, v = v * (-1.2) + x(i, j); end
        if v < dx, p2 = (v - dx)^2; end

        % p3: |P(z)| <= 1
        for k = 0:num_points
            zk = (2.0 * k) / num_points - 1.0;
            w = 0;
            for j = 1:n, w = w * zk + x(i, j); end
            if w > 1.0, p3 = p3 + (w - 1.0)^2;
            elseif w < -1.0, p3 = p3 + (w + 1.0)^2; end
        end
        scores(i) = scores(i) + p1 + p2 + p3;
    end
end

function scores = hilbert(x)
    [m, n] = size(x);
    k = sqrt(n);
    H = zeros(k, k);
    for i = 1:k
        for j = 1:k
            H(i, j) = 1.0 / (i + j - 1.0); % 1-based indices in formula 1/(i+j-1)
            % Wait, if H(i,j) = 1/(i+j-1), then H(1,1)=1.
            % My C++ code had H(i,j) = 1.0 / (i + j + 1.0) for 0-based i,j.
            % i=0, j=0 -> 1.0 / (0+0+1) = 1. OK.
        end
    end

    scores = ones(m, 1);
    for i = 1:m
        Z = reshape(x(i, :), k, k)'; % RowMajor to Matrix
        W = H * Z;
        W(logical(eye(k))) = W(logical(eye(k))) - 1.0;
        scores(i) = scores(i) + sum(abs(W(:)));
    end
end

function scores = lennard_jones(x)
    [m, n] = size(x);
    num_atoms = n / 3;
    bias = 13.7120622568;

    scores = zeros(m, 1);
    for b = 1:m
        energy = 0;
        for i = 1:num_atoms-1
            for j = i+1:num_atoms
                dx = x(b, (i-1)*3+1) - x(b, (j-1)*3+1);
                dy = x(b, (i-1)*3+2) - x(b, (j-1)*3+2);
                dz = x(b, (i-1)*3+3) - x(b, (j-1)*3+3);
                r2 = dx*dx + dy*dy + dz*dz;
                if r2 < 1e-18
                    energy = energy + 1e20;
                else
                    r6 = r2 * r2 * r2;
                    energy = energy + (1.0 / (r6 * r6)) - (2.0 / r6);
                end
            end
        end
        scores(b) = energy + bias;
    end
end
