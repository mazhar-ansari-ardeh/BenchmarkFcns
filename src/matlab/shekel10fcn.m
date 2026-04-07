% Computes the value of the Shekel-10 benchmark function.
% SCORES = SHEKEL10FCN(X) computes the value of the Shekel-10
% function at point X. SHEKEL10FCN accepts a matrix of size M-by-4
% and returns a vector SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/shekel10fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = shekel10fcn(x)
    n = size(x, 2);
    assert(n == 4, 'The Shekel-10 function is only defined on a 4D space.')

    C = [4.0, 4.0, 4.0, 4.0;
         1.0, 1.0, 1.0, 1.0;
         8.0, 8.0, 8.0, 8.0;
         6.0, 6.0, 6.0, 6.0;
         3.0, 7.0, 3.0, 7.0;
         2.0, 9.0, 2.0, 9.0;
         5.0, 5.0, 3.0, 3.0;
         8.0, 1.0, 8.0, 1.0;
         6.0, 2.0, 6.0, 2.0;
         7.0, 3.6, 7.0, 3.6];

    beta = [0.1, 0.2, 0.2, 0.4, 0.4, 0.6, 0.3, 0.7, 0.5, 0.5];

    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:10
        diff_sq_sum = sum((x - C(i, :)).^2, 2);
        scores = scores - 1.0 ./ (diff_sq_sum + beta(i));
    end
end
