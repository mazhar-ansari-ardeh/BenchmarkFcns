% Computes the value of the Xin-She Yang N. 3 function.
% The Xin-She Yang N. 3 function is a parametric function and it is
% behaviour can be controlled with two additional parameters 'beta' and
% 'm'. In this implementation, the parameters are optional and when not
% given, their default value will be used.
% SCORES = XINSHEYANGN3FCN(X) computes the value of the Xin-She Yang N. 3
% function at point X. XINSHEYANGN3FCN accepts a matrix of size P-by-N and
% returns a vetor SCORES of size P-by-1 in which each row contains the
% function value for the corresponding row of X. In this case, the default
% values of 'm=5' and 'beta=15' is used for function parameters.
% SCORES = XINSHEYANGN3FCN(X, BETA) computes the function with the given
% value of BETA for its 'beta' parameter. In this case, the default value
% of 'm=5' will be used for the parameter.
% SCORES = XINSHEYANGN3FCN(X, BETA, M) computes the function with the given
% value of M for its 'm' parameter.
% For more information, please visit:
% benchmarkfcns.info/doc/xinsheyangn3fcn
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = xinsheyangn3fcn(x, beta, m)
   if nargin < 2
       beta = 15;
   end
   if nargin < 3
       m = 5;
   end

   scores = exp(-sum((x / beta).^(2*m), 2)) - (2 * exp(-sum(x .^ 2, 2)) .* prod(cos(x) .^ 2, 2));
end
