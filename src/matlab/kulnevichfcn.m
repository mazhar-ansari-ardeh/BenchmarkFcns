function scores = kulnevichfcn(x)
% Computes the value of Kulnevich benchmark function.
% SCORES = KULNEVICHFCN(X) computes the value of the function at point X.
% KULNEVICHFCN accepts a matrix of size M-by-2 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);

    t1 = 1 ./ (1 + (x1 - 2).^2 + (x2 - 2).^2);
    t2 = 1 ./ (1 + (x1 + 2).^2 + (x2 + 2).^2);
    t3 = 1 ./ (1 + x1.^2 + x2.^2);

    scores = -(t1 + t2 + t3);
end
