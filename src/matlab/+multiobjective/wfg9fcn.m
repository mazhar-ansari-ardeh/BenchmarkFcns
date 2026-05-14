% Computes the value of the WFG9 multi-objective benchmark function.
function scores = wfg9fcn(x, num_objectives, k)
    if nargin < 2, num_objectives = 3; end
    if nargin < 3, k = 2 * (num_objectives - 1); end
    [m, n] = size(x);
    M = num_objectives;
    l = n - k;
    scores = zeros(m, M);
    for i = 1:m
        z = x(i, :) ./ (2 * (1:n));

        % T1
        t1 = z;
        for j = 1:n-1
            tail = z(j+1:n);
            t1(j) = b_param(z(j), mean(tail), 0.98, 0.02, 0.5);
        end

        % T2
        t2 = zeros(1, n);
        for j = 1:k
            t2(j) = s_deceptive(t1(j), 0.35, 0.001, 0.05);
        end
        for j = k+1:n
            t2(j) = s_multi(t1(j), 30, 95, 0.35);
        end

        % T3
        t3 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t3(j) = r_nonsep(t2(range), length(range));
        end
        t3(M) = r_nonsep(t2(k+1:n), l);

        x_final = t3;
        h = wfg_shape_concave(x_final(1:M-1));

        scores(i, :) = x_final(M) + 2*(1:M) .* h;
    end
end

function y = b_param(x, y, A, B, C)
    v = C + (1 - 2*C) * floor(0.5 - floor(0.5 - y));
    y = x.^(A + (B - A) * v);
    y = max(0, min(1, y));
end

function y = s_deceptive(x, A, B, C)
    tmp1 = floor(x - A + B) * (1 / (A - B));
    tmp2 = floor(A + B - x) * (1 / (1 - A - B));
    y = 1 + (tmp1 + tmp2) * (abs(x - A) - B) / C;
    y = max(0, min(1, y));
end

function y = s_multi(x, A, B, C)
    tmp1 = (4*A + 2) * pi * (0.5 - abs(x-C) ./ (2 * (floor(C-x) + C)));
    tmp2 = 4 * B * (abs(x-C) ./ (2 * (floor(C-x) + C))).^2;
    y = (1 + cos(tmp1) + tmp2) / (B + 2);
    y = max(0, min(1, y));
end

function y = r_nonsep(x, A)
    n = length(x);
    sum_val = 0;
    for i = 1:n
        sum_val = sum_val + x(i);
        for j = 0:A-2
            sum_val = sum_val + abs(x(i) - x(mod(i+j, n)+1));
        end
    end
    denom = n/A * (A/2) * (1 + 2*A - 2*(A/2));
    y = sum_val / denom;
    y = max(0, min(1, y));
end

function h = wfg_shape_concave(x)
    M = length(x) + 1;
    h = zeros(1, M);
    for m = 1:M
        res = 1;
        for j = 1:M-m
            res = res * sin(x(j) * pi / 2);
        end
        if m > 1
            res = res * cos(x(M-m+1) * pi / 2);
        end
        h(m) = res;
    end
end
