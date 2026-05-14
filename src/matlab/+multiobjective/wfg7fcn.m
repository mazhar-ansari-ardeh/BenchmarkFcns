% Computes the value of the WFG7 multi-objective benchmark function.
function scores = wfg7fcn(x, num_objectives, k)
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
        for j = 1:k
            tail = z(j+1:n);
            t1(j) = b_param(z(j), mean(tail), 0.98, 0.02, 0.5);
        end

        % T2
        t2 = t1;
        for j = k+1:n
            t2(j) = s_linear(t1(j), 0.35);
        end

        % T3
        t3 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t3(j) = r_sum(t2(range), ones(1, length(range)));
        end
        t3(M) = r_sum(t2(k+1:n), ones(1, l));

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

function y = s_linear(x, A)
    y = abs(x-A) ./ abs(floor(A-x) + A);
end

function y = r_sum(x, w)
    y = sum(x.*w) / sum(w);
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
