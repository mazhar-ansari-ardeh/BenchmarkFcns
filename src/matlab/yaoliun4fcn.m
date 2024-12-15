% Computes the value of the Yao Liu N. 04 function.
% SCORES = YAOLIUN4FCN(X) computes the value of the Yao Liu N. 04
% function at point X. YAOLIUN4FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = yaoliun4fcn(x)
    scores = max(abs(x), [], 2);
end
