% Computes the value of the Kursawe multi-objective benchmark function.
% SCORES = KURSAWEFCN(X) computes the value of the Kursawe
% function at point X. KURSAWEFCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2.
% For more information, please visit:
% benchmarkfcns.info/doc/kursafcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = kursawefcn(x)
    [m, n] = size(x);
    assert(n >= 2, 'The Kursawe function requires at least a 2D space.');

    scores = zeros(m, 2);

    for i = 1:n-1
        scores(:, 1) = scores(:, 1) - 10 * exp(-0.2 * sqrt(x(:, i).^2 + x(:, i+1).^2));
    end

    for i = 1:n
        scores(:, 2) = scores(:, 2) + abs(x(:, i)).^0.8 + 5 * sin(x(:, i).^3);
    end
end
