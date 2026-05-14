% Computes the value of the Quintic benchmark function.
% SCORES = QUINTICFCN(X) computes the value of the Quintic function at point X.
% QUINTICFCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = quinticfcn(x)
    scores = sum(abs(x.^5 - 3.0 * x.^4 + 4.0 * x.^3 + 2.0 * x.^2 - 10.0 * x - 4.0), 2);
end
