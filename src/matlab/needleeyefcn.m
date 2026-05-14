% Computes the value of the Needle Eye benchmark function.
% SCORES = NEEDLEEYEFCN(X) computes the value of the Needle Eye function at point X.
% NEEDLEEYEFCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
%
% The function returns 0 if all |x_i| <= 0.0001, and 1 otherwise.
function scores = needleeyefcn(x)
    max_abs = max(abs(x), [], 2);
    scores = double(max_abs > 0.0001);
end
