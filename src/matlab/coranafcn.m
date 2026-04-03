% Computes the value of the Corana benchmark function.
% SCORES = CORANAFCN(X) computes the value of the Corana function at point X.
% CORANAFCN accepts a matrix of size M-by-N and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/coranafcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = coranafcn(x)
    [m, n] = size(x);

    % Create the d vector: [1, 1000, 10, 100, 1, 1000, 10, 100, ...]
    d_base = [1.0, 1000.0, 10.0, 100.0];
    d = zeros(1, n);
    for i = 1:n
        d(i) = d_base(mod(i-1, 4) + 1);
    end
    D = repmat(d, m, 1);

    % Calculation of zi
    z_i = 0.2 * floor(abs(x / 0.2) + 0.49) .* sign(x);

    % Piecewise logic
    diff_abs = abs(x - z_i);
    mask = (diff_abs < 0.05);

    % Term when |xi - zi| < 0.05
    val1 = 0.15 * (z_i - 0.05 * sign(z_i)).^2 .* D;

    % Term otherwise
    val2 = D .* x.^2;

    result = val2;
    result(mask) = val1(mask);

    scores = sum(result, 2);
end
