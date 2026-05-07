function scores = kowalikfcn(x)
% Computes the value of Kowalik benchmark function.
% SCORES = KOWALIKFCN(X) computes the value of the function at point X.
% KOWALIKFCN accepts a matrix of size M-by-4 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    A = [0.1957, 0.1947, 0.1735, 0.1600, 0.0844, 0.0627, 0.0456, 0.0342, 0.0323, 0.0235, 0.0246];
    B = [4.0, 2.0, 1.0, 0.5, 0.25, 0.167, 0.125, 0.1, 0.0833, 0.0714, 0.0625];

    m = size(x, 1);
    scores = zeros(m, 1);
    for i = 1:11
        term = A(i) - (x1 .* (B(i)^2 + B(i) * x2)) ./ (B(i)^2 + B(i) * x3 + x4);
        scores = scores + term.^2;
    end
end
