function scores = mishran9fcn(x)
% Computes the value of Mishra's Function No. 9 benchmark function.
% SCORES = MISHRAN9FCN(X) computes the value of the function at point X.
%
% Author: Mazhar Ansari Ardeh
    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);

    f1 = 2*x1.^3 + 5*x1.*x2 + 4*x3 - 2*x1.^2.*x3 - 18;
    f2 = x1 + x3.^2 + x1.*x2.^2 + x1.*x2.^3 - 22;
    f3 = 8*x1.^2 + 2*x2.*x3 + 2*x2.^2 + 3*x3.^2 - 52;

    scores = (f1.*f2.^2.*f3 + f1.*f2.*f3.^2 + f2.^2 + (x1 + x2 - x3).^2).^2;
end
