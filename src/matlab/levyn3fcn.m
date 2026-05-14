% Computes the value of the Levy N. 3 benchmark function.
% SCORES = LEVYN3FCN(X) computes the value of the function at point X.
% LEVYN3FCN is an alias for LEVYFCN for n=3.
function scores = levyn3fcn(x)
    [m, n] = size(x);
    assert(n == 3, 'The Levy N. 3 function is only defined on a 3D space.');
    scores = levyfcn(x);
end
