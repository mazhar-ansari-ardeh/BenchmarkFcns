% Computes the value of the De Jong N. 5 benchmark function (Shekel's Foxholes).
% SCORES = DEJONGN5FCN(X) computes the value of the De Jong N. 5
% function at point X. DEJONGN5FCN accepts a matrix of size M-by-2 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = dejongn5fcn(x)
    n = size(x, 2);
    assert(n == 2, 'De Jong N. 5 function is only defined on a 2D space.');
    m = size(x, 1);

    A = [-32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32;
         -32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32];

    inner_sum = zeros(m, 1);
    for i = 1:25
        diff1 = (x(:, 1) - A(1, i)).^6;
        diff2 = (x(:, 2) - A(2, i)).^6;
        inner_sum = inner_sum + 1 ./ (i + diff1 + diff2);
    end

    scores = (0.002 + inner_sum).^-1;
end
