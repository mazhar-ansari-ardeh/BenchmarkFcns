% Computes the value of the Perm function.
% SCORES = PERMFCN(X) computes the value of the Perm function at point X.
% PERMFCN accepts a matrix of size M-by-N and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
%
% SCORES = PERMFCN(X, BETA) specifies the BETA parameter. Default is 0.5.
%
% For more information, please visit:
% benchmarkfcns.info/doc/permfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = permfcn(x, beta)
    if nargin < 2
        beta = 0.5;
    end

    n = size(x, 2);
    m = size(x, 1);
    scores = zeros(m, 1);

    j = 1:n;
    J = repmat(j, m, 1);
    xj_over_j = x ./ J;

    for i = 1:n
        j_pow_i = j.^i;
        inner_term = (j_pow_i + beta) .* (xj_over_j.^i - 1);
        scores = scores + sum(inner_term, 2).^2;
    end
end
