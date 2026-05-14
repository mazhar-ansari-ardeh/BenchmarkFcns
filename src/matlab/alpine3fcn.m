% Computes the value of the Alpine N. 3 benchmark function.
% SCORES = ALPINE3FCN(X) computes the value of the function at point X.
% ALPINE3FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = alpine3fcn(x)
    scores = sum(x.^6 .* (2.0 + sin(1.0 ./ x)), 2);
end
