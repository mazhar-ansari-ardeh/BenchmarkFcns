% Computes the value of the Step N. 3 benchmark function.
% SCORES = STEPN3FCN(X) computes the value of the function at point X.
% STEPN3FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = stepn3fcn(x)
    scores = sum(floor(x.^2), 2);
end
