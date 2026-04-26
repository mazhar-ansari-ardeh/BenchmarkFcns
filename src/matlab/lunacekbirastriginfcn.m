% Computes the value of the Lunacek Bi-Rastrigin benchmark function.
% SCORES = LUNACEKBIRASTRIGINFCN(X) computes the value of the Lunacek
% Bi-Rastrigin function at point X. LUNACEKBIRASTRIGINFCN accepts a
% matrix of size M-by-N and returns a vetor SCORES of size M-by-1 in
% which each row contains the function value for the corresponding row of X.
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = lunacekbirastriginfcn(x)
    n = size(x, 2);

    % Standard BBOB f24 parameters
    mu0 = 2.5;
    s = 1.0 - (1.0 / (2.0 * sqrt(n + 20.0) - 8.2));
    mu1 = -sqrt((mu0^2 - 1.0) / s);
    d = 1.0;

    % Quadratic terms for both basins
    sum_mu0 = sum((x - mu0).^2, 2);
    sum_mu1 = sum((x - mu1).^2, 2);

    % Deceptive basin logic
    deceptive_term = min(sum_mu0, d * n + s * sum_mu1);

    % Rastrigin-like oscillation component
    rastrigin_term = 10.0 * (n - sum(cos(2.0 * pi * (x - mu0)), 2));

    scores = deceptive_term + rastrigin_term;
end
