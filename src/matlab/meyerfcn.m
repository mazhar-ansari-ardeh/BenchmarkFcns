function scores = meyerfcn(x)
% Computes the value of Meyer (Meyer-Roth) benchmark function.
% SCORES = MEYERFCN(X) computes the value of the function at point X.
% MEYERFCN accepts a matrix of size M-by-3 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);

    T = [1.0, 2.0, 1.0, 2.0, 0.1];
    V = [1.0, 1.0, 2.0, 2.0, 0.1];
    Y = [0.057, 0.113, 0.065, 0.126, 0.0056];

    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:5
        scores = scores + ((x1 .* x3 .* T(i)) ./ (1 + x1 .* T(i) + x2 .* V(i)) - Y(i)).^2;
    end
end
