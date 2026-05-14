% Computes the value of the MOP1 (Schaffer N. 1) multi-objective benchmark function.
function scores = mop1fcn(x)
    scores = [x.^2, (x - 2.0).^2];
end
