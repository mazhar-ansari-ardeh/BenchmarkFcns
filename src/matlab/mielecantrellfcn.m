function scores = mielecantrellfcn(x)
% Computes the value of Miele-Cantrell benchmark function.
% SCORES = MIELECANTRELLFCN(X) computes the value of the function at point X.
% MIELECANTRELLFCN accepts a matrix of size M-by-4 and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);
    x4 = x(:, 4);

    scores = (exp(x1) - x2).^4 + 100*(x2 - x3).^6 + (tan(x3 - x4)).^4 + x1.^8;
end
