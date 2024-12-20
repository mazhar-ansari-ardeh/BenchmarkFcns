% Computes the value of the Wolfe function.
% SCORES = WOLFEFCN(X) computes the value of the Wolfe
% function at point X. WOLFEFCN accepts a matrix of size M-by-3 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/wolfefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = watsonfcn(x)
    i = (0:29)'; % Create column vector from 0 to 29
    a = i / 29;
    j = 0:4; % Row vector from 0 to 4
    k = 0:5; % Row vector from 0 to 5

    % Compute t1
    % t1 = sum((j + 1) .* (a .^ j) .* x(2:end), 2);
    t1 = sum((j + 1) .* (a .^ j) .* x(2:end), 2);

    % Compute t2
    t2 = sum((a .^ k) .* x, 2);

    % Compute inner
    inner = (t1 - t2 .^ 2 - 1) .^ 2;

    % Final result
    scores = sum(inner) + x(1) ^ 2;
end
