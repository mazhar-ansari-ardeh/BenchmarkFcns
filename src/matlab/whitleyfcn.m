% Computes the value of the Whitley benchmark function.
% SCORES = WHITLEYFCN(X) computes the value of the Whitley
% function at point X. WHITLEYFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = whitleyfcn(x)
    n = size(x, 2);
    m = size(x, 1);
    scores = zeros(m, 1);

    for i = 1:n
        xi = x(:, i);
        for j = 1:n
            xj = x(:, j);

            % temp = 100 * (xi^2 - xj)^2 + (1 - xj)^2
            temp = 100 * (xi.^2 - xj).^2 + (1 - xj).^2;

            % term = (temp^2 / 4000) - cos(temp) + 1
            scores = scores + (temp.^2 / 4000) - cos(temp) + 1;
        end
    end
end
