% Computes the value of the Dixon-Price benchmark function.
% SCORES = DIXONPRICEFCN(X) computes the value of the Dixon-Price function at
% point X. DIXONPRICEFCN accepts a matrix of size M-by-N and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/dixonpricefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = dixonpricefcn(x)
    n = size(x, 2);
    x1 = x(:, 1);

    scores = (x1 - 1).^2;

    if n > 1
        xi = x(:, 2:n);
        xi_prev = x(:, 1:n-1);
        i = 2:n;

        % Create a matrix of indices with the same size as xi
        I = repmat(i, size(x, 1), 1);

        term = I .* (2 * xi.^2 - xi_prev).^2;
        scores = scores + sum(term, 2);
    end
end
