% Computes the value of the Bulkin benchmark function.
% SCORES = BULKINFCN(X) computes the value of the Bulkin's function at 
% point X. BULKINFCN accepts a matrix of size M-by-2 and returns a  
% vetor SCORES of size M-by-1 in which each row contains the function value 
% for the corresponding row of X.
% For more information please visit: 
% https://en.wikipedia.org/wiki/Test_functions_for_optimization
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bulkinfcn(x)
    n = size(x, 2);
    assert(n == 2, 'Bulkin''s functions is only defined on a 2D space.')
    
    X = x(:, 1);
    X2 = X .^ 2;
    Y = x(:, 2);
    
    scores = 100 * sqrt(abs(Y - 0.01 * X2)) + 0.01 * abs(X  + 10);
end