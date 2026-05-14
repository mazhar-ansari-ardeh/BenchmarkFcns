% Computes the value of the MOP6 (Deb Disconnected) multi-objective benchmark function.
function scores = mop6fcn(x)
    scores = multiobjective.zdt3fcn(x);
end
