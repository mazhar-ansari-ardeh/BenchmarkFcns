% Computes the value of the Fonseca-Fleming multi-objective benchmark function.
% SCORES = FONSECAFLEMINGFCN(X) computes the value of the Fonseca-Fleming function
% at point X. FONSECAFLEMINGFCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2.
%
% For more information, please visit:
% benchmarkfcns.info/doc/fonsecaflemingfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = fonsecaflemingfcn(x)
    n = size(x, 2);
    m = size(x, 1);
    scores = zeros(m, 2);

    inv_sqrt_n = 1.0 / sqrt(n);

    sum_sq1 = sum((x - inv_sqrt_n).^2, 2);
    sum_sq2 = sum((x + inv_sqrt_n).^2, 2);

    scores(:, 1) = 1.0 - exp(-sum_sq1);
    scores(:, 2) = 1.0 - exp(-sum_sq2);
end
