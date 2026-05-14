% Computes the value of the MOP3 (Poloni) multi-objective benchmark function.
function scores = mop3fcn(x)
    scores = multiobjective.polonifcn(x);
end
