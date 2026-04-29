% Computes the value of the Schaffer F7 benchmark function.
% SCORES = SCHAFFERF7FCN(X) computes the value of the Schaffer F7
% function at point X. SCHAFFERF7FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = schafferf7fcn(x)
    n = size(x, 2);
    m = size(x, 1);
    scores = zeros(m, 1);

    for i = 1:n-1
        si = sqrt(x(:, i).^2 + x(:, i+1).^2);
        scores = scores + sqrt(si) .* (sin(50.0 * si.^0.2).^2 + 1.0);
    end
end
