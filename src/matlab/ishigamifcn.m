% Computes the value of the Ishigami benchmark function.
% SCORES = ISHIGAMIFCN(X) computes the value of the Ishigami function at point X.
% ISHIGAMIFCN accepts a matrix of size M-by-3 and returns a vetor SCORES of
% size M-by-1 in which each row contains the function value for the
% corresponding row of X.
%
% SCORES = ISHIGAMIFCN(X, A, B) specifies the A and B parameters.
% If not given, A defaults to 7.0 and B defaults to 0.1.
%
% For more information, please visit:
% benchmarkfcns.info/doc/ishigamifcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = ishigamifcn(x, a, b)
    if nargin < 2
        a = 7.0;
    end
    if nargin < 3
        b = 0.1;
    end

    n = size(x, 2);
    assert(n == 3, 'The Ishigami function is only defined on a 3D space.');

    x1 = x(:, 1);
    x2 = x(:, 2);
    x3 = x(:, 3);

    scores = sin(x1) + a * sin(x2).^2 + b * x3.^4 .* sin(x1);
end
