% Computes the value of the MOP7 (Viennet 3) multi-objective benchmark function.
function scores = mop7fcn(x)
    scores = multiobjective.viennet3fcn(x);
end
