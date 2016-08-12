% Computes the value of Rosenbrockfcn benchmark function.
% SCORES = ROSENBROCKFCN(X) computes the value of the Ackey function at 
% point X. ROSENBROCKFCN accepts a matrix of size M-by-N and returns a  
% vetor SCORES of size M-by-1 in which each row contains the function value 
% for each row of X.
% For more information please visit: 
% https://en.wikipedia.org/wiki/Rosenbrock_function
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = rosenbrockfcn(x)
    scores = 0;
    n = size(x, 2);
    assert(n >= 1, 'Given input X cannot be empty');
    a = 1;
    b = 100;
    for i = 1 : (n-1)
        scores = scores + (b * ((x(:, i+1) - (x(:, i).^2)) .^ 2)) + ((a - x(:, i)) .^ 2);
    end
end