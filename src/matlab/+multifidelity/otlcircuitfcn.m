% Computes the value of the multi-fidelity OTL Circuit benchmark function.
% SCORES = OTLCIRCUITFCN(X) returns a matrix of size M-by-2.
function scores = otlcircuitfcn(x)
    [m, n] = size(x);
    assert(n == 6, 'The OTL Circuit function is defined on a 6D space.');

    Rb1 = x(:,1); Rb2 = x(:,2); Rf = x(:,3); Rc1 = x(:,4); Rc2 = x(:,5); beta = x(:,6);

    Vb1 = (12 * Rb2) ./ (Rb1 + Rb2);
    term1 = ((Vb1 + 0.74) .* beta .* (Rc2 + 9)) ./ (beta .* (Rc2 + 9) + Rf);
    term2 = (11.35 * Rf) ./ (beta .* (Rc2 + 9) + Rf);
    term3 = (0.74 * Rf .* beta .* (Rc2 + 9)) ./ ((beta .* (Rc2 + 9) + Rf) .* Rc1);

    f_hf = term1 + term2 + term3;
    f_lf = term1 + term2;

    scores = [f_hf, f_lf];
end
