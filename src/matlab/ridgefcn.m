% Computes the value of the Ridge benchmark function.
% SCORES = RIDGEFCN(X) computes the value of the Ridge function at point X.
% RIDGEFCN accepts a matrix of size M-by-N and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
% SCORES = RIDGEFCN(X, D) specifies contribution coefficient of the sphere
% component of the function.
% SCORES = RIDGEFCN(X, D, ALPHA) specifies power of the sphere component of
% the function.
%
% For more information, please visit:
% benchmarkfcns.info/doc/ridgefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = ridgefcn(x, d, alpha)

    if nargin < 3
        alpha = 0.5;
    end
    if nargin < 2
        d = 1;
    end

    x1 = x(:, 1);
    scores = x1 + d * (sum(x(:, 2:end).^2, 2) .^ alpha);
end
