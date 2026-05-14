% Computes the value of the WFG6 multi-objective benchmark function.
function scores = wfg6fcn(x, num_objectives, k)
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
        for j = k+1:n
            t1(j) = s_linear(z(j), 0.35);
        end

        % T2
        t2 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t2(j) = r_nonsep(t1(range), length(range));
        end
        t2(M) = r_nonsep(t1(k+1:n), l);

        x_final = t2;
        h = wfg_shape_concave(x_final(1:M-1));

        scores(i, :) = x_final(M) + 2*(1:M) .* h;
    end
end

function y = s_linear(x, A)
    y = abs(x-A) ./ abs(floor(A-x) + A);
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
