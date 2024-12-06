% Computes the value of the Multi-fidelity Forrester_{2} function.
% SCORES = FORRESTERFCN_MF2(X) computes the value of the Forrester_{2}
% function at point X. FORRESTERFCN_MF2 accepts a matrix of size M-by-1 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/forrester_mf2fcn
% arxiv.org/pdf/2204.07867
%
% Author: Tako
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = forrester_mf2fcn(x)
     n = size(x, 1);
     assert(n == 1, 'The MF Forrester_{2} function is defined only on the 1-D space.')

     scores = (5.5 * x - 2.5).^2 .* sin(12 * x - 4);
end
