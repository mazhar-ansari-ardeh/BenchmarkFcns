function scores = griewankfcn(x)
    
    n = size(x, 2);
    
    sumcomp = 0;
    prodcomp = 1;
    
    for i = 1:n
        sumcomp = sumcomp + (x(:, i) .^ 2);
        prodcomp = prodcomp .* (cos(x(:, i) / sqrt(i)));
    end
    
    scores = (sumcomp / 4000) - prodcomp + 1;
end