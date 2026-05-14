% Computes the value of the multi-fidelity Borehole benchmark function.
% SCORES = BOREHOLEFCN(X) returns a matrix of size M-by-2.
function scores = boreholefcn(x)
    [m, n] = size(x);
    assert(n == 8, 'The Borehole function is defined on an 8D space.');

    rw = x(:,1); r = x(:,2); Tu = x(:,3); Hu = x(:,4);
    Tl = x(:,5); Hl = x(:,6); L = x(:,7); Kw = x(:,8);

    log_r_rw = log(r ./ rw);
    denom_common = 2.0 * L .* Tu ./ (log_r_rw .* rw.^2 .* Kw) + Tu ./ Tl;

    f_hf = (2.0 * pi * Tu .* (Hu - Hl)) ./ (log_r_rw .* (1.0 + denom_common));
    f_lf = (5.0 * Tu .* (Hu - Hl)) ./ (log_r_rw .* (1.5 + denom_common));

    scores = [f_hf, f_lf];
end
