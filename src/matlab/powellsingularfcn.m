% Computes the value of the Powell Singular benchmark function.
% SCORES = POWELLSINGULARFCN(X) computes the value of the Powell Singular function at
% point X. POWELLSINGULARFCN accepts a matrix of size M-by-4 and returns a vetor
% SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% For more information, please visit:
% benchmarkfcns.info/doc/powellsingularfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = powellsingularfcn(x)
    n = size(x, 2);
    assert(n == 4, 'The Powell Singular function is only defined on a 4D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    scores = (x1 + 10*x2).^2 + 5*(x3 - x4).^2 + (x2 - 2*x3).^4 + 10*(x1 - x4).^4;
end
