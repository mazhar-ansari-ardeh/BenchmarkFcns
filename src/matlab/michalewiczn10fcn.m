% Computes the value of the Michalewicz N. 10 benchmark function.
% SCORES = MICHALEWICZN10FCN(X) computes the value of the function at point X.
% MICHALEWICZN10FCN is an alias for MICHALEWICZFCN for n=10.
function scores = michalewiczn10fcn(x)
    [m, n] = size(x);
    assert(n == 10, 'The Michalewicz N. 10 function is only defined on a 10D space.');
    scores = michalewiczfcn(x, 10);
end
