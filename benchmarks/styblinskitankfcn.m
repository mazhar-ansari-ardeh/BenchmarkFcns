% Computes the value of the Styblinski-Tank benchmark function.
% SCORES = LEVIN13FCN(X) computes the value of the Styblinski-Tank function 
% at point X. LEVIN13FCN accepts a matrix of size M-by-2 and returns a  
% vetor SCORES of size M-by-1 in which each row contains the function value 
% for the corresponding row of X.
% For more information please visit: 
% https://en.wikipedia.org/wiki/Test_functions_for_optimization
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = styblinskitankfcn(x)
    n = size(x, 2);
    scores = 0;
    for i = 1:n
        scores = scores + ((x(:, i) .^4) - (16 * x(:, i) .^ 2) + (5 * x(:, i)));
    end
    scores = 0.5 * scores;
end