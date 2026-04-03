% Computes the value of the Katsuura benchmark function.
% SCORES = KATSUURAFCN(X) computes the value of the Katsuura function at point X.
% KATSUURAFCN accepts a matrix of size M-by-N and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/katsuurafcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = katsuurafcn(x)
    [m, n] = size(x);
    n_inv_sq = 10 / (n^2);
    exp_val = 10 / (n^1.2);

    inner_sum = zeros(m, n);
    for j = 1:32
        two_pow_j = 2^j;
        val = two_pow_j * x;
        inner_sum = inner_sum + abs(val - round(val)) / two_pow_j;
    end

    i = 1:n;
    prod_terms = 1 + inner_sum .* i;
    scores = n_inv_sq * (prod(prod_terms .^ exp_val, 2) - 1);
end
