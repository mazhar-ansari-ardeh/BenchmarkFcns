% Computes the value of the Michalewicz benchmark function.
% SCORES = MICHALEWICZFCN(X) computes the value of the Michalewicz function
% at point X. MICHALEWICZFCN accepts a matrix of size M-by-N and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for each row of X.
%
% SCORES = MICHALEWICZFCN(X, M) computes the function with the given
% value of M for its 'm' parameter. If not given, M defaults to 10.
%
% For more information, please visit:
% benchmarkfcns.info/doc/michalewiczfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = michalewiczfcn(x, m)
    if nargin < 2
        m = 10;
    end

    n = size(x, 2);
    i = 1:n;

    % Create a matrix of indices with the same size as x
    I = repmat(i, size(x, 1), 1);

    term2 = sin(I .* (x.^2) ./ pi).^(2 * m);
    scores = -sum(sin(x) .* term2, 2);
end
