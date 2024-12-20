% Computes the value of Wavy benchmark function.
% SCORES = WAVYFCN(X) computes the value of the Wavy function at point
% X. WAVYFCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1 in which each row contains the function value for each row
% of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = wavyfcn(x, k)
    if nargin < 2
       k = 10;
    end
    x2 = (x .^ 2 / 2);
    n = size(x, 2);

    scores = 1 - (1/n) * sum(cos(k * x) .* exp(-x2), 2);
end
