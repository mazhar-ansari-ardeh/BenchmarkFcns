% Computes the value of the DEB (ZDT3 alias) multi-objective benchmark function.
% SCORES = DEBFCN(X) computes the value of the DEB function
% at point X. DEBFCN accepts a matrix of size M-by-N and returns
% a matrix SCORES of size M-by-2.
function scores = debfcn(x)
    scores = multiobjective.zdt3fcn(x);
end
