---
layout: page
resource: true
title: Drop-Wave Function
categories: optimization, benchmark
tags: 2-dimensional, continuous, unimodal
fname: dropwavefcn
functionname: Drop-Wave Function
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

$$f(x, y) = 1 + \frac{cos(12\sqrt{x^{2} + y^{2}})}{(0.5(x^{2} + y^{2}) + 2)}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

The contour of the function: 
![{{page.functionname}} Contour]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on 2-dimensional space. 
* The function is unimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-5.2, 5.2]$ for $i = 1, 2$.

# Global Minima
$f(\textbf{x}^{\ast}) = -1$ at $\textbf{x}^{\ast} = (0, 0)$

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
% Computes the value of the Schwefel benchmark function.
% SCORES = SCHWEFELFCN(X) computes the value of the Schwefel function at 
% point X. SCHWEFELFCN accepts a matrix of size M-by-2 and returns a  
% vetor SCORES of size M-by-1 in which each row contains the function value 
% for the corresponding row of X.
% For more information please visit: 
% 
% Author: Mazhar Ansari Ardeh
function scores = schwefelfcn(x)
    n = size(x, 2);
    scores = 418.9829 * n - (sum(x .* sin(sqrt(abs(x))), 2));
end
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = 1 + \frac{cos(12\sqrt{x^{2} + y^{2}})}{(0.5(x^{2} + y^{2}) + 2)}
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano