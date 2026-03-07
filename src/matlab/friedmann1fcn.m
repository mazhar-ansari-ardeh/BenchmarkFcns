% Computes the value of the Friedman No. 1 benchmark function.
% SCORES = FRIEDMAN1FCN(X) computes the value of the Friedman No. 1 function at
% point X. FRIEDMAN1FCN accepts a matrix of size M-by-10 and returns a vetor
% SCORES of size M-by-1 in which each row contains the function value for
% the corresponding row of X.
% SCORES = FRIEDMAN1FCN(X, RND) specifies whether to add random noise.
function scores = friedmann1fcn(x, rnd)
    [m, n] = size(x);
    assert(n == 10, 'The Friedman No. 1 function is only defined on a 10D space.')

    if nargin < 2 || rnd == false
        epsilon = 0;
    else
        epsilon = randn(m, 1);
    end

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);
    x5 = x(:, 5);

    term1 = 10 .* sin(pi .* x1 .* x2);

    term2 = 20 .* (x3 - 0.5).^2;

    term3 = 10 .* x4;
    term4 = 5 .* x5;

    scores = term1 + term2 + term3 + term4 + epsilon;
end
