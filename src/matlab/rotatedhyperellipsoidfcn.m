% Computes the value of the Rotated Hyper-Ellipsoid (Schwefel 1.2) benchmark function.
% SCORES = ROTATEDHYPERELLIPSOIDFCN(X) computes the value of the function at point X.
% ROTATEDHYPERELLIPSOIDFCN is an alias for SCHWEFEL12FCN.
function scores = rotatedhyperellipsoidfcn(x)
    scores = schwefel12fcn(x);
end
