% Computes the value of the Brown benchmark function.
% SCORES = BROWNFCN(X) computes the value of the Brown function at point X.
% BROWNFCN accepts a matrix of size M-by-N and returns a vetor SCORES of 
% size M-by-1 in which each row contains the function value for the 
% corresponding row of X.
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = brownfcn(x)
    
    n = size(x, 2);  
    scores = 0;
    
    x = x .^ 2;
    for i = 1:(n-1)
        scores = scores + x(:, i) .^ (x(:, i+1) + 1) + x(:, i+1).^(x(:, i) + 1);
    end
end