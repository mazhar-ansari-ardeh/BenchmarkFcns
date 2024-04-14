% Computes the value of Sphere benchmark function.
% SCORES = SPHEREFCN(X) computes the value of the Ackey function at
% point X. SPHEREFCN accepts a matrix of size M-by-N and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% each row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/spherefcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function f = spherefcn(x)
    f = sum(x .^ 2, 2);
end
