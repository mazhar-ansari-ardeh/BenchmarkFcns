% Computes the value of the WFG4 multi-objective benchmark function.
function scores = wfg4fcn(x, num_objectives, k)
    if nargin < 2, num_objectives = 3; end
    if nargin < 3, k = 2 * (num_objectives - 1); end
    [m, n] = size(x);
    M = num_objectives;
    l = n - k;
    scores = zeros(m, M);
    for i = 1:m
        z = x(i, :) ./ (2 * (1:n));

        % T1
        t1 = zeros(1, n);
        for j = 1:n
            t1(j) = s_multi(z(j), 30, 10, 0.35);
        end

        % T2
        t2 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t2(j) = r_sum(t1(range), ones(1, length(range)));
        end
        t2(M) = r_sum(t1(k+1:n), ones(1, l));

        x_final = t2;
        h = wfg_shape_concave(x_final(1:M-1));

        scores(i, :) = x_final(M) + 2*(1:M) .* h;
    end
end

function y = s_multi(x, A, B, C)
    tmp1 = (4*A + 2) * pi * (0.5 - abs(x-C) ./ (2 * (floor(C-x) + C)));
    tmp2 = 4 * B * (abs(x-C) ./ (2 * (floor(C-x) + C))).^2;
    y = (1 + cos(tmp1) + tmp2) / (B + 2);
    y = max(0, min(1, y));
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
