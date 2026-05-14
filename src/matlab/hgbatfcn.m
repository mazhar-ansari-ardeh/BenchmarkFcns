% Computes the value of the HGBat benchmark function.
% SCORES = HGBATFCN(X, ALPHA) computes the value of the HGBat
% function at point X with parameter ALPHA (default 0.5).
%
% Author: Mazhar Ansari Ardeh
function scores = hgbatfcn(x, alpha)
    if nargin < 2 || isempty(alpha)
        alpha = 0.5;
    end

    x2 = sum(x.^2, 2);
    x_sum = sum(x, 2);

    scores = abs(x2 - 100.0).^(2 * alpha) + (0.5 * x2 + x_sum) / 100.0 + 0.5;
end
