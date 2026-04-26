% Computes the value of the Viennet 3 multi-objective benchmark function.
% SCORES = VIENNET3FCN(X) computes the value of the Viennet 3 function
% at point X. VIENNET3FCN accepts a matrix of size M-by-2 and returns
% a matrix SCORES of size M-by-3.
function scores = viennet3fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Viennet 3 function is only defined on a 2D space.');
    m = size(x, 1);
    scores = zeros(m, 3);
    x1 = x(:, 1);
    x2 = x(:, 2);
    x12_x22 = x1.^2 + x2.^2;
    scores(:, 1) = 0.5 * x12_x22 + sin(x12_x22);
    scores(:, 2) = (3*x1 - 2*x2 + 4).^2 / 8 + (x1 - x2 + 1).^2 / 27 + 15;
    scores(:, 3) = 1 ./ (x12_x22 + 1) - 1.1 * exp(-x12_x22);
end
