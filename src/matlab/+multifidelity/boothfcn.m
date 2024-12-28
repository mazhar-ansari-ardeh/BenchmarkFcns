% Computes the value of the Booth function.
% SCORES = BOOTHFCN(X) computes the value of the Booth
% function at point X. BOOTHFCN accepts a matrix of size M-by-1 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please refer to:
% Dong, H., Song, B., Wang, P. et al. Multi-fidelity information
% fusion based on prediction of kriging. Struct Multidisc Optim
% 51, 1267-1280 (2015) doi:10.1007/s00158-014-1213-9
%
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = boothfcn(x)
    n = size(x, 2);
    assert(n == 2, 'The multi-fidelity Booth function is defined only on the 2-D space.')
    X = x(:, 1);
    Y = x(:, 2);
    NX = [0.4*X, Y];

    scores_1 = boothfcn(x);
    scores_2 = boothfcn(NX) + 1.7 .* X .* Y - X + 2 * Y;
    scores = [scores_1, scores_2];
end
