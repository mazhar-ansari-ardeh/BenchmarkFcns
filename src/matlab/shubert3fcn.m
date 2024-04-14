% Computes the value of the Shubert 3 function.
% SCORES = SHUBEERT3FCN(X) computes the value of the Shubert 3
% function at point X. SHUBEERT3FCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/shubert3fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = shubert3fcn(x)
    n = size(x, 2);

    scores = 0;
    for i = 1:n
        for j = 1:5
            scores = scores + j * sin(((j + 1) * x(:, i)) + j);
        end
    end
end
