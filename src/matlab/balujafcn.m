function scores = balujafcn(x)
% Computes the value of Baluja (Schwefel 1.2) benchmark function.
% SCORES = BALUJAFCN(X) computes the value of the Baluja function at point
% X. BALUJAFCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:m
        val = 0;
        for j = 1:n
            val = val + sum(x(i, 1:j))^2;
        end
        scores(i) = val;
    end
end
