% Computes the value of the Qing N. 2 benchmark function.
% SCORES = QINGN2FCN(X) computes the value of the function at point X.
% QINGN2FCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = qingn2fcn(x)
    [m, n] = size(x);
    sin2x = sum(sin(x).^2, 2);

    sum_comp = sum(x.^2, 2) / 4000.0;
    prod_comp = ones(m, 1);
    for i = 1:n
        prod_comp = prod_comp .* cos(x(:, i) / sqrt(i));
    end
    griewank = sum_comp - prod_comp + 1.0;

    scores = sin2x + griewank;
end
