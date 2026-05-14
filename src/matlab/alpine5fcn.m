% Computes the value of the Alpine N. 5 benchmark function.
% SCORES = ALPINE5FCN(X) computes the value of the function at point X.
% ALPINE5FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = alpine5fcn(x)
    scores = sum(x.^2 + sin(x).^2, 2);
end
