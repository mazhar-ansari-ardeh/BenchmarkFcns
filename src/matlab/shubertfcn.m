% Computes the value of the Shubert function.
% SCORES = SHUBEERTFCN(X) computes the value of the Shubert
% function at point X. SHUBEERTFCN accepts a matrix of size M-by-N and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% See also: shubert3fcn, shubert4fcn
% For more information, please visit:
% benchmarkfcns.info/doc/shubertfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = shubertfcn(x)
    n = size(x, 2);

    scores = 1;
    for i = 1:n
        inner_sum = 0;
        for j = 1:5
            inner_sum = inner_sum + j * cos(((j + 1) * x(:, i)) + j);
        end
        scores = inner_sum .* scores;
    end
end
