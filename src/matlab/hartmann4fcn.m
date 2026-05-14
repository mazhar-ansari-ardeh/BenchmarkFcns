% Computes the value of the Hartmann N. 4 (4D) benchmark function.
% SCORES = HARTMANN4FCN(X) computes the value of the function at point X.
% HARTMANN4FCN accepts a matrix of size M-by-4 and returns a vector SCORES of size M-by-1.
function scores = hartmann4fcn(x)
    [m, n] = size(x);
    assert(n == 4, 'The Hartmann 4 function only accepts 4D inputs');

    alpha = [1.0, 1.2, 3.0, 3.2];
    A = [10.0, 3.0, 17.0, 3.5;
         0.05, 10.0, 17.0, 0.1;
         3.0, 3.5, 1.7, 10.0;
         17.0, 8.0, 0.05, 10.0];
    P = 1e-4 * [1312, 1696, 5569, 124;
                2329, 4135, 8307, 3736;
                2348, 1451, 3522, 2883;
                4047, 8828, 8732, 5743];

    scores = zeros(m, 1);
    for i = 1:4
        sum_inner = zeros(m, 1);
        for j = 1:4
            sum_inner = sum_inner + A(i, j) * (x(:, j) - P(i, j)).^2;
        end
        scores = scores - alpha(i) * exp(-sum_inner);
    end
end
