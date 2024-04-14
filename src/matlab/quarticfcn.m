% Computes the value of Quartic benchmark function.
% SCORES = QUARTICFCN(X) computes the value of the Quartic function at
% point X. QUARTICFCN accepts a matrix of size M-by-N and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% each row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/quarticfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = quarticfcn(x)
    n = size(x, 2);

    x_powered = x .^ 4;
    indices = repmat(1:n, size(x, 1), 1);

    scores = sum(indices .* x_powered, 2);

    scores = scores + rand;
end
