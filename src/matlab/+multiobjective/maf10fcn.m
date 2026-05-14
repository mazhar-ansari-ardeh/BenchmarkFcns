% Computes the value of the MaF10 multi-objective benchmark function.
function scores = maf10fcn(x, num_objectives, k)
    if nargin < 2, num_objectives = 3; end
    if nargin < 3, k = 2 * (num_objectives - 1); end
    [m, n] = size(x);
    M = num_objectives;
    l = n - k;

    scores = zeros(m, M);
    for r = 1:m
        z = x(r, :) ./ (2 * (1:n));

        t1 = z;
        for i = 1:n
            t1(i) = s_linear(z(i), 0.35);
        end

        t2 = t1;
        for i = 1:n
            t2(i) = b_flat(t1(i), 0.8, 0.75, 0.85);
        end

        t3 = t2;
        for i = 1:n
            t3(i) = b_poly(t2(i), 0.02);
        end

        t4 = zeros(1, M);
        for i = 1:(M - 1)
            start_idx = (i - 1) * k / (M - 1) + 1;
            sz = k / (M - 1);
            w = 2 * (start_idx : start_idx + sz - 1);
            t4(i) = r_sum(t3(start_idx : start_idx + sz - 1), w);
        end
        w_last = 2 * (k + 1 : n);
        t4(M) = r_sum(t3(k + 1 : n), w_last);

        h = zeros(1, M);
        for i = 1:(M - 1)
            prod_val = 1.0;
            for j = 1:(M - i)
                prod_val = prod_val * (1.0 - cos(t4(j) * pi / 2.0));
            end
            if i > 1
                prod_val = prod_val * (1.0 - sin(t4(M - i + 1) * pi / 2.0));
            end
            h(i) = prod_val;
        end
        h(M) = 1.0 - t4(1) - cos(10 * pi * t4(1) + pi / 2.0) / (10 * pi);

        for i = 1:M
            scores(r, i) = t4(M) + 2 * i * h(i);
        end
    end
end

function res = b_poly(x, alpha)
    res = max(0, min(1, x))^alpha;
end

function res = b_flat(x, A, B, C)
    tmp1 = min(0, floor(x - B)) * A * (B - x) / B;
    tmp2 = max(0, ceil(x - C)) * (1.0 - A) * (x - C) / (1.0 - C);
    res = max(0, min(1, A + tmp1 + tmp2));
end

function res = s_linear(x, A)
    res = max(0, min(1, abs(x - A) / abs(floor(A - x) + A)));
end

function res = r_sum(x, w)
    res = sum(x .* w) / sum(w);
end
