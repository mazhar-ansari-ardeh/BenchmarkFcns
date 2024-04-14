% Computes the value of Ackley N. 4 benchmark function.
% SCORES = ACKLEYN4FCN(X) computes the value of the Ackey function at point
% X. ACKLEYN4FCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1 in which each row contains the function value for each row
% of X.
% For more information, please visit:
% benchmarkfcns.info/doc/ackleyn4fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = ackleyn4fcn(x)
    [m, n] = size(x);

    scores = zeros(m, 1);

   for i = 1:m
      for j = 1:(n - 1)
            scores = scores + exp(-0.2) .* sqrt( x(i, j) .^ 2 + x(i, j + 1) .^ 2 ) ...
            + 3 * ( cos(2 * x(i, j)) + sin(2 * x(i, j + 1)) );
      end
   end
end
