% Computes the value of Zakharov benchmark function.
% SCORES = ZAKHAROVFCN(X) computes the value of the Zakharov function at
% point X. ZAKHAROVFCN accepts a matrix of size M-by-N and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% each row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/zakharovfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zakharovfcn(x)
    [m, n] = size(x);

    % Calculate component 1
    comp1 = sum(x.^2, 2);

    I = repmat(1:n, m, 1)

    % Calculate component 2

    comp2 = 0.5 * I .* x;
    comp2 = sum(comp2, 2)

    % Compute final scores
    scores = comp1 + comp2.^2 + comp2.^4
end
