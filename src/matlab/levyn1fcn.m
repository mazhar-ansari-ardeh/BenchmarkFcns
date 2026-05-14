% Computes the value of the Levy N. 1 benchmark function.
% SCORES = LEVYN1FCN(X) computes the value of the function at point X.
% LEVYN1FCN is an alias for LEVYFCN for n=1.
function scores = levyn1fcn(x)
    [m, n] = size(x);
    assert(n == 1, 'The Levy N. 1 function is only defined on a 1D space.');
    scores = levyfcn(x);
end
