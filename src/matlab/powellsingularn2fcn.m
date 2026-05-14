% Computes the value of the Powell-Singular N. 2 benchmark function.
% SCORES = POWELLSINGULARN2FCN(X) computes the value of the function at point X.
% POWELLSINGULARN2FCN is an alias for POWELLSINGULARFCN for n=4.
function scores = powellsingularn2fcn(x)
    [m, n] = size(x);
    assert(n == 4, 'The Powell-Singular N. 2 function is only defined on a 4D space.');
    scores = powellsingularfcn(x);
end
