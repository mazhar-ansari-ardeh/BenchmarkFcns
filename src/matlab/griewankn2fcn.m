% Computes the value of the Griewank N. 2 benchmark function.
% SCORES = GRIEWANKN2FCN(X) computes the value of the function at point X.
% GRIEWANKN2FCN is an alias for GRIEWANKFCN for n=2.
function scores = griewankn2fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Griewank N. 2 function is only defined on a 2D space.');
    scores = griewankfcn(x);
end
