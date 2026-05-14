% Computes the value of the Sine Envelope Sine Wave (Schaffer F6 scalable) benchmark function.
% SCORES = SINEENVELOPESINEWAVEFCN(X) computes the value of the function at point X.
% SINEENVELOPESINEWAVEFCN accepts a matrix of size M-by-N and returns a vector SCORES of size M-by-1.
function scores = sineenvelopesinewavefcn(x)
    [m, n] = size(x);
    scores = zeros(m, 1);
    for i = 1:(n-1)
        xi = x(:, i);
        xi_plus_1 = x(:, i+1);
        x2y2 = xi.^2 + xi_plus_1.^2;
        numerator = (sin(sqrt(x2y2))).^2 - 0.5;
        denominator = (1.0 + 0.001 * x2y2).^2;
        scores = scores + 0.5 + numerator ./ denominator;
    end
end
