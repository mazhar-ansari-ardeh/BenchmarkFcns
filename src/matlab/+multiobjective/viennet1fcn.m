% Computes the value of the Viennet 1 multi-objective benchmark function.
% SCORES = VIENNET1FCN(X) computes the value of the Viennet 1 function
% at point X. VIENNET1FCN accepts a matrix of size M-by-2 and returns
% a matrix SCORES of size M-by-3.
function scores = viennet1fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Viennet 1 function is only defined on a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 3);
    x1 = x(:, 1);
    x2 = x(:, 2);
    scores(:, 1) = x1.^2 + (x2 - 1).^2;
    scores(:, 2) = x1.^2 + (x2 + 1).^2 + 1;
    scores(:, 3) = (x1 - 1).^2 + x2.^2 + 2;
end
