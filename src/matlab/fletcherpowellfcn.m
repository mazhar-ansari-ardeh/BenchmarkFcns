function scores = fletcherpowellfcn(x)
% Computes the value of Fletcher-Powell benchmark function.
% SCORES = FLETCHERPOWELLFCN(X) computes the value of the function at point X.
% FLETCHERPOWELLFCN accepts a matrix of size M-by-N and returns a vetor SCORES
% of size M-by-1.
%
% Author: Mazhar Ansari Ardeh
    [m, n] = size(x);

    % Use fixed seed for reproducibility matching the C++ implementation
    prev_rng = rng();
    rng(42 + n);

    a_mat = randi([-100, 100], n, n);
    b_mat = randi([-100, 100], n, n);
    alpha_vec = -pi + (2 * pi) * rand(n, 1);

    rng(prev_rng); % Restore user's rng state

    Ai = zeros(n, 1);
    for i = 1:n
        for j = 1:n
            Ai(i) = Ai(i) + a_mat(i, j) * sin(alpha_vec(j)) + b_mat(i, j) * cos(alpha_vec(j));
        end
    end

    scores = zeros(m, 1);
    for k = 1:m
        for i = 1:n
            Bi = 0;
            for j = 1:n
                Bi = Bi + a_mat(i, j) * sin(x(k, j)) + b_mat(i, j) * cos(x(k, j));
            end
            scores(k) = scores(k) + (Ai(i) - Bi)^2;
        end
    end
end
