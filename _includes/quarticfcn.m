% Computes the value of Quartic benchmark function.
% SCORES = QUARTICFCN(X) computes the value of the Quartic function at 
% point X. QUARTICFCN accepts a matrix of size M-by-N and returns a vetor 
% SCORES of size M-by-1 in which each row contains the function value for
% each row of X.
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = quarticfcn(x)

    n = size(x, 2);
    
    scores = 0;
    for i = 1:n
        scores = scores + i *(x(:, i) .^ 4);
    end
     
    scores = scores + rand;
end