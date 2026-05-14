% Computes the value of the MOP5 (Viennet 1) multi-objective benchmark function.
function scores = mop5fcn(x)
    scores = multiobjective.viennet1fcn(x);
end
