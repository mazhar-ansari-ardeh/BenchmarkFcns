% Computes the value of the Schaffer N. 2 benchmark function.
% SCORES = SCHAFFERN2FCN(X) computes the value of the Schaffer N. 2 function
% at point X. SCHAFFERN2FCN accepts a matrix of size M-by-2 and returns a
% vetor SCORES of size M-by-1 in which each row contains the function value
% for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/schaffern2fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = schaffern2fcn(x)

    n = size(x, 2);
    assert(n == 2, 'The Schaffer N. 2 function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);

    sincomponent = sin( (X .^ 2) - (Y .^ 2) ).^2;

    scores = 0.5 + ((sincomponent - 0.5) ./ (1 + 0.001 * (X .^2 + Y .^2)) .^2 ) ;
end
