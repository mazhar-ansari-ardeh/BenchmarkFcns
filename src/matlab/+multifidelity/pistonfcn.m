% Computes the value of the multi-fidelity Piston benchmark function.
% SCORES = PISTONFCN(X) returns a matrix of size M-by-2.
function scores = pistonfcn(x)
    [m, n] = size(x);
    assert(n == 7, 'The Piston function is defined on a 7D space.');

    M = x(:,1); S = x(:,2); V0 = x(:,3); k = x(:,4);
    P0 = x(:,5); Ta = x(:,6); T0 = x(:,7);

    A = P0 .* S + 19.62 * M - k .* V0 ./ S;
    V = (S ./ (2 * A)) .* (sqrt(A.^2 + 4 * k .* (V0 + P0 .* V0 ./ T0 .* Ta)) - A);
    f_hf = 2 * pi * sqrt(M ./ (k + S.^2 .* (P0 .* V0 ./ T0) .* Ta ./ V.^2));
    f_lf = f_hf + 10.0; % Simple bias for LF

    scores = [f_hf, f_lf];
end
