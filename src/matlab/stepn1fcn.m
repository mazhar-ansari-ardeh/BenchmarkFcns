% Computes the value of the Step N. 1 benchmark function.
% SCORES = STEPN1FCN(X) computes the value of the function at point X.
% STEPN1FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = stepn1fcn(x)
    scores = sum(floor(abs(x)), 2);
end
