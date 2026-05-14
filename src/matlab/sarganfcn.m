% Computes the value of the Sargan benchmark function.
% SCORES = SARGANFCN(X) computes the value of the Sargan function at point X.
% SARGANFCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = sarganfcn(x)
    sum_sq = sum(x.^2, 2);
    sum_all = sum(x, 2);
    scores = sum_sq + 0.4 * (sum_all.^2 - sum_sq);
end
