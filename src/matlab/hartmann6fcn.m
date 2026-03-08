% Computes the value of the Hartmann N. 6 benchmark function.
% SCORES = HARTMANN6FCN(X) computes the value of the Hartmann N. 6
% function at point X. `HARTMANN6FCN` accepts a matrix of size M-by-6 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
function SCORES = hartmann6fcn(x)
    [m, n] = size(x);
    assert(n == 6, 'Hartman6 function is only defined on a 6D space.')

    alpha = [1.0, 1.2, 3.0, 3.2]';

    A = [10, 3, 17, 3.5, 1.7, 8;
         0.05, 10, 17, 0.1, 8, 14;
         3, 3.5, 1.7, 10, 17, 8;
         17, 8, 0.05, 10, 0.1, 14];

    P = [0.1312, 0.1696, 0.5569, 0.0124, 0.8283, 0.5886;
         0.2329, 0.4135, 0.8307, 0.3736, 0.1004, 0.9991;
         0.2348, 0.1451, 0.3522, 0.2883, 0.3047, 0.6650;
         0.4047, 0.8828, 0.8732, 0.5743, 0.1091, 0.0381];

    SCORES = zeros(m, 1);

    for i = 1:4
        % Vectorized exponent calculation: sum(A_ij * (xj - P_ij)^2)
        % We subtract row P(i,:) from all rows of x simultaneously
        diff_sq = (x - P(i,:)).^2;
        exponent = diff_sq * A(i,:)';

        SCORES = SCORES - alpha(i) .* exp(-exponent);
    end
end
