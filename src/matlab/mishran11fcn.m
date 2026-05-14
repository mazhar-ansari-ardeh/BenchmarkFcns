function scores = mishran11fcn(x)
% Computes the value of Mishra's Function No. 11 benchmark function.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    am = sum(abs(x), 2) / n;
    gm = prod(abs(x), 2).^(1/n);
    scores = (am - gm).^2;
end
