---
layout: page
resource: true
title: Bohachevsky N. 1 Function
categories: optimization, benchmark
tags: 2-dimensional continuous convex unimodal
fname: bohachevskyn1fcn
functionname: Bohachevskyn N. 1 Function
excerpt: The Bohachevsky N. 1 function is a multimodal, 2-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = x^2 + 2y^2 -0.3cos(3\pi x)-0.4cos(4\pi y)+0.7$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

The contour of the function: 
![{{page.functionname}} Contour]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on 2-dimensional space. 
* The function is unimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-100, 100]$ for $i = 1, 2$.

# Global Minima
The function has one local minimum at: $f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (0, 0)$

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
% Computes the value of Bohachevsky N. 1 benchmark function.
% SCORES = BOHACHEVSKYN1FCN(X) computes the value of the Bohachevsky N. 1
% function at point X. BOHACHEVSKYN1FCN accepts a matrix of size M-by-N and 
% returns a vetor SCORES of size M-by-1 in which each row contains the 
% function value for each row of X.
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = bohachevskyn1fcn(x)
    n = size(x, 2);
    assert(n == 2, 'The Bohachevsky N. 1 function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);
    
    scores = (X .^ 2) + (2 * Y .^ 2) - (0.3 * cos(3 * pi * X)) - (0.4 * cos(4 * pi * Y)) + 0.7;
end
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = x^2 + 2y^2 -0.3cos(3\pi x)-0.4cos(4\pi y)+0.7
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano/boha.html
