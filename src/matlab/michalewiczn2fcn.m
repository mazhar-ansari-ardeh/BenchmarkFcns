% Computes the value of the Michalewicz N. 2 benchmark function.
% SCORES = MICHALEWICZN2FCN(X) computes the value of the function at point X.
% MICHALEWICZN2FCN is an alias for MICHALEWICZFCN for n=2.
function scores = michalewiczn2fcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Michalewicz N. 2 function is only defined on a 2D space.');
    scores = michalewiczfcn(x, 10);
end
