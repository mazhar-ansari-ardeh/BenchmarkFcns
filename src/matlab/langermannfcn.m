% Computes the value of the Langermann benchmark function.
% SCORES = LANGERMANNFCN(X) computes the value of the Langermann function at point X.
% LANGERMANNFCN accepts a matrix of size M-by-2 and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/langermannfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = langermannfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Langermann function is only defined on a 2D space.');

    a = [3, 5; 5, 2; 2, 1; 1, 7; 7, 9];
    c = [1, 2, 5, 2, 3];

    m = size(x, 1);
    scores = zeros(m, 1);

    for i = 1:5
        ai = a(i, :);
        % Vectorized sum of squares for all points against center ai
        sum_sq = sum((x - ai).^2, 2);

        scores = scores - c(i) * (exp(-1/pi * sum_sq) .* cos(pi * sum_sq));
    end
end
