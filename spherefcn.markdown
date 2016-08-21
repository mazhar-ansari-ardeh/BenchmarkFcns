---
layout: page
title: Sphere Function
categories: optimization, benchmark
---
<head>
	<script type="text/x-mathjax-config">
	  MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});
	</script>
	<script type="text/javascript" async
	  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_CHTML">
	</script>
</head>


# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, x_2, ..., x_n) = {\sum_{i=1}^{n} x_i^{2}}.$$

{%endraw%}

![Sphere Function]({{site.baseurl}}/spherefcn.png){:class="img-responsive"}

# Implementation
An implementation of the Sphere Function is provided below.

**Sphere function** can be implemented with a `for` loop that iterates over all the components of the input vector but, MATLAB and Octave have built-in facilities that makes the implementation more efficient and concise.

{% highlight MATLAB%}
% Computes the value of Sphere benchmark function.
% SCORES = SPHEREFCN(X) computes the value of the Ackey function at 
% point X. SPHEREFCN accepts a matrix of size M-by-N and returns a vetor 
% SCORES of size M-by-1 in which each row contains the function value for
%  each row of X.
% For more information please visit: 
% https://en.wikipedia.org/wiki/Test_functions_for_optimization
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function f = spherefcn(x)
    f = sum(x .^ 2, 2);
end
{% endhighlight %}
