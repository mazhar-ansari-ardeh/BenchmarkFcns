% This function computes the Weierstrass function for each row of a matrix X,
% using a fully vectorized approach.
%
% Inputs:
%   X: A matrix where each row is a vector of dimension n.
%   a: A scalar parameter.
%   b: A scalar parameter.
%   kmax: An integer, the maximum value for k.
%
% Output:
%   y: A column vector where each element is the result for the corresponding row of X.
function y = weierstrassfcn(X, a, b, kmax)
    if nargin < 2
        a = 0.5;
    end
    if nargin < 3
        b = 3;
    end
    if nargin < 4
        kmax = 20;
    end

    [num_rows, n] = size(X);

    k = 0:kmax;

    k_reshaped = reshape(k, 1, 1, []); % 1x1x(kmax+1)

    X_reshaped = reshape(X + 0.5, num_rows, 1, n); % num_rows x 1 x n

    b_powers = b .^ k;

    term1_cos_input = 2 * pi * b_powers .* X_reshaped;
    term1 = a .^ k .* cos(term1_cos_input); % num_rows x (kmax+1) x n

    % Sum along the k dimension (the second dimension of term1)
    sum_k_term1 = sum(term1, 2); % num_rows x 1 x n

    sum_over_n = sum(sum_k_term1, 3); % num_rows x 1

    sum_k_term2 = sum(a .^ k .* cos(pi * b .^ k));

    y = sum_over_n - n * sum_k_term2;
end
