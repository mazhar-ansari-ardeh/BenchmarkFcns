% Computes the value of the multi-fidelity Robot Arm benchmark function.
% SCORES = ROBOTARMFCN(X) returns a matrix of size M-by-2.
function scores = robotarmfcn(x)
    [m, n] = size(x);
    assert(n == 8, 'The Robot Arm function is defined on an 8D space.');

    th1 = x(:,1); th2 = x(:,2); th3 = x(:,3); th4 = x(:,4);
    L1 = x(:,5); L2 = x(:,6); L3 = x(:,7); L4 = x(:,8);

    function res = compute_pos(th1, th2, th3, th4, L1, L2, L3, L4)
        u = L1 .* cos(th1) + L2 .* cos(th1+th2) + L3 .* cos(th1+th2+th3) + L4 .* cos(th1+th2+th3+th4);
        v = L1 .* sin(th1) + L2 .* sin(th1+th2) + L3 .* sin(th1+th2+th3) + L4 .* sin(th1+th2+th3+th4);
        res = sqrt(u.^2 + v.^2);
    end

    f_hf = compute_pos(th1, th2, th3, th4, L1, L2, L3, L4);
    f_lf = compute_pos(th1, th2, th3, th4, L1+0.05, L2+0.05, L3+0.05, L4+0.05);

    scores = [f_hf, f_lf];
end
