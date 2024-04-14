% Computes the value of the Happy Cat benchmark function.
% SCORES = HAPPYCATFCN(X) computes the value of the Happy Cat function at
% point X. HAPPYCATFCN accepts a matrix of size M-by-N and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% the corresponding row of X.
% SCORES = HAPPYCAT(X, ALPHA) specifies power of the sphere component of
% the function.
% For more information, please visit:
% benchmarkfcns.info/doc/happycatfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = happycatfcn(x, alpha)

    if nargin < 2
        alpha = 0.5;
    end

    n = size(x, 2);
    x2 = sum(x .* x, 2);
    scores = ((x2 - n).^2).^(alpha) + (0.5*x2 + sum(x,2))/n + 0.5;
end
