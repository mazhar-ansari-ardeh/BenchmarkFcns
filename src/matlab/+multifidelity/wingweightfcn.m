% Computes the value of the multi-fidelity Wing Weight benchmark function.
% SCORES = WINGWEIGHTFCN(X) returns a matrix of size M-by-2.
function scores = wingweightfcn(x)
    [m, n] = size(x);
    assert(n == 10, 'The Wing Weight function is defined on a 10D space.');

    Sw = x(:,1); Wfw = x(:,2); A = x(:,3); Lambda = x(:,4) * pi / 180.0;
    q = x(:,5); lambda = x(:,6); tc = x(:,7); Nz = x(:,8);
    Wdg = x(:,9); Wp = x(:,10);

    cos_L = cos(Lambda);
    term1 = 0.036 * Sw.^0.758 .* Wfw.^0.0035;
    term2 = (A ./ cos_L.^2).^0.6 .* q.^0.006 .* lambda.^0.04;
    term3 = (100.0 * tc ./ cos_L).^-0.3;
    term4 = (Nz .* Wdg).^0.49;

    f_hf = term1 .* term2 .* term3 .* term4 + Sw .* Wp;
    f_lf = 0.9 * f_hf + 10.0;

    scores = [f_hf, f_lf];
end
