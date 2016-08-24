---
layout: page
title: Schwefel Function
categories: optimization, benchmark
tags: continuous, multimodal
fname: schwefelfcn
functionname: Schwefel Function
---
<head>
	<script type="text/x-mathjax-config">
	  MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});
	</script>
	<script type="text/javascript" async
	  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_CHTML">
	</script>
</head>


## Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, x_2, ..., x_n) = 418.9829d -{\sum_{i=1}^{n} x_i sin(\sqrt{|x_i|})}.$$

{%endraw%}

# Description and features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function can be defined on n-dimensional space. 
* The function is multimodal.

# Inout Domain
The function can be defined on any input domain but it is usually evaluated on the hypercube $x_i \in [-500, 500]$ for $i = 1..n$.

# Global Minima
$f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (420.9687, ..., 420.9687)$

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

The contour of the function: 
![{{page.functionname}} Contour]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. **{{page.functionname}}** can be implemented with a `for` loop that iterates over all the components of the input vector but, MATLAB and Octave have built-in facilities that makes the implementation more efficient and concise.

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

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = f(x_1, x_2, ..., x_n) = 418.9829d -{\sum_{i=1}^{n} x_i sin(\sqrt{|x_i|})}
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano/spheref.html
* https://en.wikipedia.org/wiki/Test_functions_for_optimization