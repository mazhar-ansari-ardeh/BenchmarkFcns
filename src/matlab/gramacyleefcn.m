% Computes the value of the Gramacy & Lee benchmark function.
% SCORES = GRAMACYLEEFCN(X) computes the value of the Gramacy & Lee
% function at point X. GRAMACYLEEFCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/gramacyleefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = gramacyleefcn(x)
    n = size(x, 2);
    assert(n == 1, 'Gramacy & Lee function is only defined on a 1-D space.')

    scores = (sin(10 .* pi .* x) ./ (2 * x) ) + ((x - 1) .^ 4);
end
