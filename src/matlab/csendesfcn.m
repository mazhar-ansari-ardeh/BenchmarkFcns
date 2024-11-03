% Computes the value of the Csendes function.
% SCORES = CSENDESFCN(X) computes the value of the Csendes
% function at point X. CSENDESFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = csendesfcn(x)
    scores = sum(x .^ 6 .* (2 + sin(1 ./ x)), 2);
end
