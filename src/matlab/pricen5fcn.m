% Computes the value of the Price N. 5 benchmark function.
% SCORES = PRICEN5FCN(X) computes the value of the function at point X.
% PRICEN5FCN is an alias for GOLDSTEINPRICEFCN.
function scores = pricen5fcn(x)
    scores = goldsteinpricefcn(x);
end
