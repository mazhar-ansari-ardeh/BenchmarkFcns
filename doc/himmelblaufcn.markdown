---
layout: page
resource: true
title: Himmelblau Function
categories: optimization, benchmark
tags: 2-dimensional continuous multimodal non-convex
fname: himmelblaufcn
functionname: Himmelblau Function
excerpt: The Himmelblau function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = (x^{2} + y - 11)^{2} + (x + y^{2} - 7)^{2}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

The contour of the function: 
![{{page.functionname}} Contour]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on the 2-dimensional space. 
* The function is multimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-6, 6]$ for $i = 1, 2$.

# Global Minima
The function has four local minima at: 

* $f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (3, 2)$
* $f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (-2.805118, 3.283186)$
* $f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (-3.779310, -3.283186)$
* $f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (3.584458, -1.848126)$

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
% Computes the value of the Himmelblau's benchmark function.
% SCORES = HIMMELBLAUFCN(X) computes the value of the Himmelblau's
% function at point X. HIMMELBLAUFCN accepts a matrix of size M-by-2 
% and returns a vetor SCORES of size M-by-1 in which each row contains the 
% function value for the corresponding row of X.
% For more information please visit: 
% https://en.wikipedia.org/wiki/Himmelblau's_function
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = himmelblaufcn(x)
    n = size(x, 2);
    assert(n == 2, 'Himmelblau''s function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);
    
    scores = ((X .^ 2 + Y - 11) .^2) + ((X + (Y .^ 2) - 7) .^ 2);
end
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = (x^{2} + y - 11)^{2} + (x + y^{2} - 7)^{2}
{% endhighlight %}

# References:
* https://en.wikipedia.org/wiki/Himmelblau%27s_function
