---
layout: page
resource: true
title: Drop-Wave Function
categories: optimization, benchmark
tags: 2-dimensional continuous unimodal non-convex
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

$$f(x, y) = - \frac{1 + cos(12\sqrt{x^{2} + y^{2}})}{(0.5(x^{2} + y^{2}) + 2)}$$

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
* The function is multimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-5.2, 5.2]$ for $i = 1, 2$.

# Global Minima
$f(\textbf{x}^{\ast}) = -1$ at $\textbf{x}^{\ast} = (0, 0)$

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
% Computes the value of the Drop-Wave benchmark function.
% SCORES = DROPWAVEFCN(X) computes the value of the Drop-Wave function at 
% point X. DROPWAVEFCN accepts a matrix of size M-by-2 and returns a  
% vetor SCORES of size M-by-1 in which each row contains the function value 
% for the corresponding row of X.
% For more information please visit: 
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = dropwavefcn(x)
    n = size(x, 2);
    assert(n == 2, 'Drop-Wave function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);
    
    numeratorcomp = 1 + cos(12 * sqrt(X .^ 2 + Y .^ 2));
    denumeratorcom = (0.5 * (X .^ 2 + Y .^ 2)) + 2;
    scores = - numeratorcomp ./ denumeratorcom;
end
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = - \frac{1 + cos(12\sqrt{x^{2} + y^{2}})}{(0.5(x^{2} + y^{2}) + 2)}
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano
