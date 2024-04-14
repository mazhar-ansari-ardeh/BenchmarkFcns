% Computes the value of the Brown benchmark function.
% SCORES = BROWNFCN(X) computes the value of the Brown function at point X.
% BROWNFCN accepts a matrix of size M-by-N and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/brownfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = brownfcn(x)
    n = size(x, 2);

    x_squared = x .^ 2;
    scores = sum(x_squared(:, 1:n-1) .^ (x_squared(:, 2:n) + 1) + x_squared(:, 2:n) .^ (x_squared(:, 1:n-1) + 1), 2);
end
