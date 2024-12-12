% Computes the value of the Forrester function.
% SCORES = FORRESTERFCN(X) computes the value of the Forrester
% function at point X. FORRESTERFCN accepts a matrix of size M-by-1 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please refer to:
% arxiv.org/pdf/2204.07867
%
% Author: Tako
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = forresterfcn(x)
     n = size(x, 2);
     assert(n == 1, 'The Forrester function is defined only on the 1-D space.')

     scores_1 = forresterfcn(x);
     scores_2 = forrester_mf2fcn(x);
     scores_3 = forrester_mf3fcn(x);
     scores_4 = forrester_mf4fcn(x);
     scores = [scores_1, scores_2, scores_3, scores_4];
end

function scores = forrester_mf2fcn(x)
     scores = (5.5 * x - 2.5).^2 .* sin(12 * x - 4);
end

function scores = forrester_mf3fcn(x)
     scores = (0.75 * (6 * x - 2).^2 .* sin(12 * x - 4)) + (5 * (x - 0.5)) - 2;
end

function scores = forrester_mf4fcn(x)
     scores = (0.5 * (6 * x - 2).^2 .* sin(12 * x - 4)) + (10 * (x - 0.5)) - 5;
end
