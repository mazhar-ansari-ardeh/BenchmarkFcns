% Computes the value of the Rana function.
% SCORES = RANAFCN(X) computes the value of the Alpine N. 1
% function at point X. RANAFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = ranafcn(x)
    x1 = x(:, 1);
    scores = sum(
        x .* sin(sqrt(abs(x1 - x + 1))) .* cos(sqrt(abs(x1 + x + 1))) + ...
        (x1 + 1) .* sin(sqrt(abs(x1 + x + 1))) .* cos(sqrt(abs(x1 - x + 1))),
        2
    );
end
