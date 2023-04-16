% Computes the value of Zakharov benchmark function.
% SCORES = ZAKHAROVFCN(X) computes the value of the Zakharov function at 
% point X. ZAKHAROVFCN accepts a matrix of size M-by-N and returns a vetor 
% SCORES of size M-by-1 in which each row contains the function value for
% each row of X.
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zakharovfcn(x)

    n = size(x, 2);
    comp1 = 0;
    comp2 = 0;
    
    for i = 1:n
        comp1 = comp1 + (x(:, i) .^ 2);
        comp2 = comp2 + (0.5 * i * x(:, i));
    end
     
    scores = comp1 + (comp2 .^ 2) + (comp2 .^ 4);
end