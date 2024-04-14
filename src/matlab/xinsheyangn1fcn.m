% Computes the value of the Xin-She Yang function.
% SCORES = XINSHEYANGN1FCN(X) computes the value of the Xin-She Yang
% function at point X. XINSHEYANGN1FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/xinsheyangn1fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = xinsheyangn1fcn(x)
    [m, n] = size(x, 2);

    exponents = 1:n;
    rand_values = rand(m, n);

    scores = sum(rand_values .* (abs(x) .^ exponents), 2);
end
