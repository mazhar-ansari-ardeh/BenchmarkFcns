% Computes the value of the Michalewicz N. 5 benchmark function.
% SCORES = MICHALEWICZN5FCN(X) computes the value of the function at point X.
% MICHALEWICZN5FCN is an alias for MICHALEWICZFCN for n=5.
function scores = michalewiczn5fcn(x)
    [m, n] = size(x);
    assert(n == 5, 'The Michalewicz N. 5 function is only defined on a 5D space.');
    scores = michalewiczfcn(x, 10);
end
