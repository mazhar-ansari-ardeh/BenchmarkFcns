% Computes the value of the Venter Sobiezcczanski-Sobieski benchmark function.
% SCORES = VENTERSOBIEZCCZANSKIFCN(X) computes the value of the function at point X.
% VENTERSOBIEZCCZANSKIFCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = ventersobiezcczanskifcn(x)
    scores = sum(x.^2 - 100.0 * cos(x).^2 - 100.0 * cos(x.^2 / 30.0), 2);
end
