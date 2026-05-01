% Computes the value of Gallagher's Gaussian 101-me Peaks benchmark function.
% SCORES = GALLAGHER101FCN(X) computes the value of the Gallagher's 101-me Peaks
% function at point X. GALLAGHER101FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = gallagher101fcn(x)
    [m, n] = size(x);

    % Use fixed seed for reproducibility matching the C++ version
    rng(101);

    w = zeros(101, 1);
    y = zeros(101, n);
    C = cell(101, 1);

    % Global peak
    w(1) = 10.0;
    y(1, :) = zeros(1, n);
    C{1} = eye(n);

    for i = 2:101
        w(i) = 1.1 + (9.1 - 1.1) * rand();
        y(i, :) = -4.0 + (4.0 - -4.0) * rand(1, n);

        diag_vals = zeros(1, n);
        for j = 1:n
            diag_vals(j) = 1000.0^(0.5 * (j-1)/(n-1));
        end
        C{i} = diag(diag_vals);
    end

    max_vals = zeros(m, 1);
    for i = 1:101
        diff = x - repmat(y(i, :), m, 1);
        % Vectorized exponent calculation
        exponent = -0.5 / n * sum((diff * C{i}).^2, 2);
        max_vals = max(max_vals, w(i) * exp(exponent));
    end

    scores = 10.0 - max_vals;
end
