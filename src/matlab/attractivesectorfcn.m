% Computes the value of the Attractive Sector benchmark function.
% SCORES = ATTRACTIVESECTORFCN(X) computes the value of the Attractive
% Sector function at point X. ATTRACTIVESECTORFCN accepts a matrix of
% size M-by-N and returns a vector SCORES of size M-by-1 in which each row
% contains the function value for each row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/attractivesectorfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = attractivesectorfcn(x)
    condition = ones(size(x));
    condition(x > 0) = 100^2;
    scores = sum(condition .* (x .^ 2), 2);
end
