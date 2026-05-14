% Computes the value of the Trigonometric N. 2 benchmark function.
% SCORES = TRIGONOMETRICN2FCN(X) computes the value of the function at point X.
% TRIGONOMETRICN2FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = trigonometricn2fcn(x)
    scores = 1.0 + sum(8.0 * sin(7.0 * (x - 0.9).^2).^2 + ...
                       6.0 * sin(14.0 * (x - 0.9).^2).^2 + (x - 0.9).^2, 2);
end
