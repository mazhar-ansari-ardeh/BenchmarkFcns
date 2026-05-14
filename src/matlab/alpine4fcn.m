% Computes the value of the Alpine N. 4 benchmark function.
% SCORES = ALPINE4FCN(X) computes the value of the function at point X.
% ALPINE4FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = alpine4fcn(x)
    scores = sum(x.^2 .* sin(x).^2 + 0.1, 2);
end
