% Computes the value of the Elliptic benchmark function.
% SCORES = ELLIPTICFCN(X) computes the value of the Elliptic
% function at point X. ELLIPTICFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = ellipticfcn(x)
    n = size(x, 2);
    m = size(x, 1);

    i = 0:n-1;
    powers = 10.^(6 * i / (n - 1));
    Coeffs = repmat(powers, m, 1);

    scores = sum(Coeffs .* x.^2, 2);
end
