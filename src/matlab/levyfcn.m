% Computes the value of the Levy benchmark function.
% SCORES = LEVYFCN(X) computes the value of the Levy function at point X.
% LEVYFCN accepts a matrix of size M-by-N and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/levyfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = levyfcn(x)
    n = size(x, 2);
    w = 1 + (x - 1) / 4;

    w1 = w(:, 1);
    wn = w(:, n);

    term1 = sin(pi * w1).^2;
    term3 = (wn - 1).^2 .* (1 + sin(2 * pi * wn).^2);

    scores = term1 + term3;

    if n > 1
        w_sub = w(:, 1:n-1);
        term2 = sum((w_sub - 1).^2 .* (1 + 10 * sin(pi * w_sub + 1).^2), 2);
        scores = scores + term2;
    end
end
