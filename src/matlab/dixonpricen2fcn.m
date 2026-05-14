% Computes the value of the Dixon-Price N. 2 benchmark function.
% SCORES = DIXONPRICEN2FCN(X) computes the value of the function at point X.
% DIXONPRICEN2FCN is an alias for DIXONPRICEFCN for n=2.
function scores = dixonpricen2fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Dixon-Price N. 2 function is only defined on a 2D space.');
    scores = dixonpricefcn(x);
end
