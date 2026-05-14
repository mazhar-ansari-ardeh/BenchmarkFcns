% Computes the value of the Chen Bird (Multi-Modal) benchmark function.
% SCORES = CHENBIRDFCN(X) computes the value of the Chen Bird function at point X.
% CHENBIRDFCN accepts a matrix of size M-by-2 and returns a vector SCORES of size M-by-1.
%
% Properties:
% - Global minimum: -2000
% - Location of global minimum: (7/18, 13/18)
% - Number of dimensions: 2
% - Recommended domain: [-500, 500]^2
% - Modality: multimodal
function scores = chenbirdfcn(x)
    [m, n] = size(x);
    assert(n == 2, 'The Chen Bird function is only defined on a 2D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);

    term1 = (x1 - 0.4 * x2 - 0.1).^2;
    term2 = (2.0 * x1 + x2 - 1.5).^2;

    f1 = -0.001 ./ (1e-6 + term1);
    f2 = -0.001 ./ (1e-6 + term2);

    scores = f1 + f2;
end
