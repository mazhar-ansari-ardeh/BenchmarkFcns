% Computes the value of the Yao Liu N. 09 function.
% SCORES = YAOLIUN9FCN(X) computes the value of the Yao Liu N. 09
% function at point X. YAOLIUN9FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = yaoliun9fcn(x)
    scores = sum(x.^2 - 10 * cos(2 * pi * x) + 10, 2);
end
