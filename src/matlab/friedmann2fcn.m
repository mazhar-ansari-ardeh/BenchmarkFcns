% Computes the value of the Friedman No. 2 benchmark function.
% SCORES = FRIEDMAN2FCN(X) computes the value of the Friedman No. 2 function at
% point X. FRIEDMAN2FCN accepts a matrix of size M-by-4 and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% the corresponding row of X.
% SCORES = FRIEDMAN2FCN(X, SIGMA) specifies the standard deviation of the added Gaussian noise.
function scores = friedmann2fcn(x, sigma)
    [m, n] = size(x);
    assert(n == 4, 'The Friedman No. 2 function is only defined on a 4D space.')

    if nargin < 2 || sigma == 0
        epsilon = 0;
    else
        epsilon = sigma .* randn(size(groundTruth));
    end

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    term_inner = x2 .* x3 - (1 ./ (x2 .* x4));
    groundTruth = sqrt(x1.^2 + term_inner.^2);

    scores = groundTruth + epsilon;
end
