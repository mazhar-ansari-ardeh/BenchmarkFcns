% Computes the value of the Styblinski-Tank benchmark function.
% SCORES = STYBLINSKITANKFCN(X) computes the value of the Styblinski-Tank
% function at point X. STYBLINSKITANKFCN accepts a matrix of size M-by-2
% and returns a vetor SCORES of size M-by-1 in which each row contains the
% function value for the corresponding row of X.
% For more information, please visit:
% benchmarkfcns.info/doc/styblinskitankfcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = styblinskitankfcn(x)
    % Calculate the intermediate terms
    term1 = x .^ 4;
    term2 = 16 * x .^ 2;
    term3 = 5 * x;

    scores = sum(term1 - term2 + term3, 2);

    scores = 0.5 * scores;
end
