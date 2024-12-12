% Computes the value of the Forrester function.
% SCORES = FORRESTERFCN(X) computes the value of the Forrester
% function at point X. FORRESTERFCN accepts a matrix of size M-by-1 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/forresterfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = forresterfcn(x)
     n = size(x, 2);
     assert(n == 1, 'The Forrester function is defined only on the 1-D space.')

     scores = (6 * x - 2).^2 .* sin(12 * x - 4);
end
