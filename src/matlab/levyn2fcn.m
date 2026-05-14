% Computes the value of the Levy N. 2 benchmark function.
% SCORES = LEVYN2FCN(X) computes the value of the function at point X.
% LEVYN2FCN is an alias for LEVYFCN for n=2.
function scores = levyn2fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Levy N. 2 function is only defined on a 2D space.');
    scores = levyfcn(x);
end
