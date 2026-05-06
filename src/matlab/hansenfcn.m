function scores = hansenfcn(x)
% Computes the value of Hansen benchmark function.
% SCORES = HANSENFCN(X) computes the value of the function at point X.
% HANSENFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    sum1 = 0;
    sum2 = 0;
    for i = 1:5
        sum1 = sum1 + i * cos((i - 1) * x1 + i);
        sum2 = sum2 + i * cos((i + 1) * x2 + i);
    end

    scores = sum1 .* sum2;
end
