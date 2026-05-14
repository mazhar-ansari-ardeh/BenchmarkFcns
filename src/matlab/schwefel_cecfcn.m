% Computes the value of the Modified Schwefel benchmark function (CEC version).
% SCORES = SCHWEFEL_CECFCN(X) computes the value of the Modified
% Schwefel function at point X.
%
% Author: Mazhar Ansari Ardeh
function scores = schwefel_cecfcn(x)
    [m, n] = size(x);
    z = x + 420.9687;

    mask_high = z > 500;
    mask_low = z < -500;

    z(mask_high) = 500 - mod(z(mask_high) - 500, 500);
    z(mask_low) = -500 + mod(-500 - z(mask_low), 500);

    scores = 418.9829 * n - sum(z .* sin(sqrt(abs(z))), 2);
end
