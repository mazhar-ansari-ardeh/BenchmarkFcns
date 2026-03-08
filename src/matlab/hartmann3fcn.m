% Computes the value of the Hartmann N. 3 benchmark function.
% SCORES = HARTMANN3FCN(X) computes the value of the Hartmann N. 3
% function at point X. `HARTMANN3FCN` accepts a matrix of size M-by-3 and
% returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
function SCORES = hartmann3fcn(x)
    [m, n] = size(x);
    assert(n == 3, 'Hartmann3 function is only defined on a 3D space.')

    alpha = [1.0, 1.2, 3.0, 3.2]';
    A = [3.0, 10, 30;
         0.1, 10, 35;
         3.0, 10, 30;
         0.1, 10, 35];
    P = [0.3689, 0.1170, 0.2673;
         0.4699, 0.4387, 0.7470;
         0.1091, 0.8732, 0.5547;
         0.0381, 0.5743, 0.8828];

    SCORES = zeros(m, 1);

    for i = 1:4
        % Calculate: sum_{j=1}^3 A_ij * (xj - P_ij)^2
        exponent = A(i,1).*(x(:,1)-P(i,1)).^2 + ...
                   A(i,2).*(x(:,2)-P(i,2)).^2 + ...
                   A(i,3).*(x(:,3)-P(i,3)).^2;

        SCORES = SCORES - alpha(i) .* exp(-exponent);
    end
end
