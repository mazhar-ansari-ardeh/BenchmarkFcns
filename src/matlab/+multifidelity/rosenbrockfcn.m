% Computes the value of the MF Rosenbrock benchmark function.
% SCORES = ROSENBROCKFCN(X) computes the value of the MF Rosenbrock function
% at point X. ROSENBROCKFCN accepts a matrix of size M-by-N and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% arxiv.org/pdf/2204.07867
%
% Author: Tako
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = rosenbrockfcn(x)
  assert(size(x, 2) >= 1, 'Given input X cannot be empty');

  a = -2;
  b = 50;

  x_2 = x.^2;

  term1 = b * ((x(:, 2:end) - x_2(:, 1:end-1)).^2);
  term2 = (a - x(:, 1:end-1)).^2;

  scores_2 = sum(term1 + term2, 2) - sum(0.5 *  x(:, 1:end));

  scores_1 = rosenbrockfcn(x);

  scores = [scores_1, scores_2];
end
