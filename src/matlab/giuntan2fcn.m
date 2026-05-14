% Computes the value of the Giunta N. 2 benchmark function.
% SCORES = GIUNTAN2FCN(X) computes the value of the function at point X.
% GIUNTAN2FCN is an alias for GIUNTAFCN for n=4.
function scores = giuntan2fcn(x)
    [m, n] = size(x);
    assert(n == 4, 'The Giunta N. 2 function is only defined on a 4D space.');
    scores = giuntafcn(x);
end
