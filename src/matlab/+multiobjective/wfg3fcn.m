% Computes the value of the WFG3 multi-objective benchmark function.
function scores = wfg3fcn(x, num_objectives, k)
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
            t2(k+j) = r_sum(t1(k + 2*(j-1) + 1 : k + 2*j), ones(1, 2));
        end

        % T3
        t3 = zeros(1, M);
        for j = 1:M-1
            range = (j-1)*k/(M-1)+1 : j*k/(M-1);
            t3(j) = r_sum(t2(range), ones(1, length(range)));
        end
        t3(M) = r_sum(t2(k+1:end), ones(1, l/2));

        x_final = t3;
        h = wfg_shape_linear(x_final(1:M-1));

        scores(i, :) = x_final(M) + 2*(1:M) .* h;
    end
end

function y = s_linear(x, A)
    y = abs(x-A) ./ abs(floor(A-x) + A);
end

function y = r_sum(x, w)
    y = sum(x.*w) / sum(w);
end

function h = wfg_shape_linear(x)
    M = length(x) + 1;
    h = zeros(1, M);
    for m = 1:M
        res = 1;
        for j = 1:M-m
            res = res * x(j);
        end
        if m > 1
            res = res * (1 - x(M-m+1));
        end
        h(m) = res;
    end
end
