% Computes the value of the Dixon-Price N. 3 benchmark function.
% SCORES = DIXONPRICEN3FCN(X) computes the value of the function at point X.
% DIXONPRICEN3FCN is an alias for DIXONPRICEFCN for n=3.
function scores = dixonpricen3fcn(x)
    [m, n] = size(x);
    assert(n == 3, 'The Dixon-Price N. 3 function is only defined on a 3D space.');
    scores = dixonpricefcn(x);
end
