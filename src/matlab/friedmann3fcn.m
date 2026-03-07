% Computes the value of the Friedman No. 3 benchmark function.
% SCORES = FRIEDMAN3FCN(X) computes the value of the Friedman No. 3 function at
% point X. FRIEDMAN3FCN accepts a matrix of size M-by-4 and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% the corresponding row of X.
% SCORES = FRIEDMAN3FCN(X, SIGMA) specifies the standard deviation of the added Gaussian noise.
function scores = friedmann3fcn(x, sigma)
    n = size(x, 2);
    assert(n == 4, 'The Friedman No. 3 function is only defined on a 4D space.')
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    numerator = (x2 .* x3) - (1 ./ (x2 .* x4));
    groundTruth = atan(numerator ./ x1);

    if nargin > 1 && sigma > 0
        scores = groundTruth + sigma .* randn(size(groundTruth));
    else
        scores = groundTruth;
    end
end
