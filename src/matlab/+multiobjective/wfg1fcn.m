% Computes the value of the WFG1 multi-objective benchmark function.
function scores = wfg1fcn(x, num_objectives, k)
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
        t2 = t1;
        t2(k+1:n) = b_flat(t1(k+1:n), 0.8, 0.75, 0.85);

        % T3
        t3 = b_poly(t2, 0.02);

        % T4
        t4 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t4(j) = r_sum(t3(range), ones(1, length(range)));
        end
        t4(M) = r_sum(t3(k+1:n), ones(1, l));

        x_final = t4;
        h = wfg_shape_convex(x_final(1:M-1));
        % Mixed shape for last objective
        h(M) = (1 - x_final(1) - cos(10*pi*x_final(1) + pi/2) / (10*pi));

        scores(i, :) = x_final(M) + 2*(1:M) .* h;
    end
end

function y = s_linear(x, A)
    y = abs(x-A) ./ abs(floor(A-x) + A);
end

function y = b_flat(x, A, B, C)
    y = A + min(0, floor(x-B)) .* A .* (B-x)/B + max(0, ceil(x-C)) .* (1-A) .* (x-C)/(1-C);
end

function y = b_poly(x, alpha)
    y = x.^alpha;
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
