% Computes the value of the WFG2 multi-objective benchmark function.
function scores = wfg2fcn(x, num_objectives, k)
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
        t1(k+1:n) = s_linear(z(k+1:n), 0.35);

        % T2
        t2 = zeros(1, k + l/2);
        t2(1:k) = t1(1:k);
        for j = 1:l/2
            t2(k+j) = r_nonsep(t1(k + 2*(j-1) + 1 : k + 2*j), 2);
        end

        % T3
        t3 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t3(j) = r_sum(t2(range), ones(1, length(range)));
        end
        t3(M) = r_sum(t2(k+1:end), ones(1, l/2));

        x_final = t3;
        h = wfg_shape_convex(x_final(1:M-1));
        h(M) = 1 - x_final(1) * (cos(5 * x_final(1) * pi))^2; % Disconnected

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
    denom = n/A * floor(A/2) * (1 + 2*A - 2*floor(A/2));
    y = sum_val / denom;
end

function y = r_sum(x, w)
    y = sum(x.*w) / sum(w);
end

function h = wfg_shape_convex(x)
    M = length(x) + 1;
    h = zeros(1, M);
    for m = 1:M
        res = 1;
        for j = 1:M-m
            res = res * (1 - cos(x(j) * pi / 2));
        end
        if m > 1
            res = res * (1 - sin(x(M-m+1) * pi / 2));
        end
        h(m) = res;
    end
end
