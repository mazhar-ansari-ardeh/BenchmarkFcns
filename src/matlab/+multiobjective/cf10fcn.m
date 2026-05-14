% Computes the value of the CF10 multi-objective benchmark function.
function scores = cf10fcn(x, return_constraints)
    if nargin < 2, return_constraints = false; end
    [m, n] = size(x);
    M = 3;

    J1 = 3:3:n;
    J2 = 4:3:n;
    J3 = 5:3:n;
    if n < 3
        J1 = []; J2 = []; J3 = [];
    end

    x1 = x(:, 1);
    x2 = x(:, 2);

    y = zeros(m, n);
    for j = 3:n
        y(:, j) = x(:, j) - 2.0 * x2 .* sin(2.0 * pi * x1 + j * pi / n);
    end

    h = @(t) 4.0 * t.^2 - cos(20.0 * pi * t ./ sqrt(repmat(1:size(t, 2), size(t, 1), 1))) + 1.0;
    % Wait, the formula for h is different in some sources.
    % In CES-487: h(t) = 4t^2 - cos(20*pi*t/sqrt(j)) + 1

    g1 = zeros(m, 1);
    if ~isempty(J1)
        for j = J1
            g1 = g1 + 4.0 * y(:, j).^2 - cos(20.0 * pi * y(:, j) / sqrt(j)) + 1.0;
        end
    end

    g2 = zeros(m, 1);
    if ~isempty(J2)
        for j = J2
            g2 = g2 + 4.0 * y(:, j).^2 - cos(20.0 * pi * y(:, j) / sqrt(j)) + 1.0;
        end
    end

    g3 = zeros(m, 1);
    if ~isempty(J3)
        for j = J3
            g3 = g3 + 4.0 * y(:, j).^2 - cos(20.0 * pi * y(:, j) / sqrt(j)) + 1.0;
        end
    end

    f1 = cos(0.5 * pi * x1) .* cos(0.5 * pi * x2) + 2.0 / length(J1) * g1;
    f2 = cos(0.5 * pi * x1) .* sin(0.5 * pi * x2) + 2.0 / length(J2) * g2;
    f3 = sin(0.5 * pi * x1) + 2.0 / length(J3) * g3;

    constraint = 1.0 - (f1.^2 + f2.^2 + f3.^2) + 1.0 * sin(2.0 * pi * (f1.^2 + f2.^2 + f3.^2));

    if return_constraints
        scores = [f1, f2, f3, constraint];
    else
        scores = [f1, f2, f3];
    end
end
