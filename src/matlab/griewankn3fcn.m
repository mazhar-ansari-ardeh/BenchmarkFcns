% Computes the value of the Griewank N. 3 benchmark function.
% SCORES = GRIEWANKN3FCN(X) computes the value of the function at point X.
% GRIEWANKN3FCN is an alias for GRIEWANKFCN for n=3.
function scores = griewankn3fcn(x)
    [m, n] = size(x);
    assert(n == 3, 'The Griewank N. 3 function is only defined on a 3D space.');
    scores = griewankfcn(x);
end
