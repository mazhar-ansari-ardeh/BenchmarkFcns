% Computes the value of the Expanded Griewank plus Rosenbrock (F8F2) benchmark function.
% SCORES = F8F2FCN(X) computes the value of the F8F2
% function at point X. F8F2FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = f8f2fcn(x)
    n = size(x, 2);
    m = size(x, 1);
    scores = zeros(m, 1);

    for i = 1:n
        next_idx = mod(i, n) + 1;
        xi = x(:, i);
        xnext = x(:, next_idx);

        rosen = 100 * (xi.^2 - xnext).^2 + (xi - 1).^2;

        % Griewank of the rosen value
        scores = scores + (rosen.^2 / 4000) - cos(rosen) + 1;
    end
end
