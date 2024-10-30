% Computes the value of the Cosine Mixture benchmark function.
% SCORES = COSINEMIXTUEREFCN(X) computes the value of the Cosine Mixture function at
% point X. COSINEMIXTUEREFCN accepts a matrix of size M-by-N and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = cosinemixturefcn(x)
    scores = -0.1 * sum(cos(5 * pi * x), 2) - sum(x.^2, 2)
end
