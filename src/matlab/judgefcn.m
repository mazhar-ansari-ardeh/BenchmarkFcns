function scores = judgefcn(x)
% Computes the value of Judge benchmark function.
% SCORES = JUDGEFCN(X) computes the value of the function at point X.
% JUDGEFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    A = [4.284, 4.149, 3.877, 0.533, 2.211, 2.389, 2.145, 3.231, 1.998, 1.379, ...
         2.106, 1.428, 1.011, 2.179, 2.858, 1.388, 1.651, 1.593, 1.046, 2.152];
    B = [0.286, 0.973, 0.384, 0.276, 0.973, 0.543, 0.957, 0.948, 0.543, 0.797, ...
         0.936, 0.889, 0.006, 0.828, 0.399, 0.617, 0.939, 0.784, 0.072, 0.889];
    C = [0.645, 0.585, 0.310, 0.058, 0.455, 0.779, 0.259, 0.202, 0.028, 0.099, ...
         0.142, 0.296, 0.175, 0.180, 0.842, 0.039, 0.103, 0.620, 0.158, 0.704];

    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:20
        scores = scores + (x1 + B(i) * x2 + C(i) * x2.^2 - A(i)).^2;
    end
end
