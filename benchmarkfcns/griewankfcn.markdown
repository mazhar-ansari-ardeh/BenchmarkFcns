---
layout: page
resource: true
title: Griewank Function
categories: optimization, benchmark
tags: n-dimensional continuous unimodal non-convex
fname: griewankfcn
functionname: Griewank Function
excerpt: The Griewank function is a unimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, ..., x_n) = 1 + \sum_{i=1}^{n} \frac{x_i^{2}}{4000} - \prod_{i=1}^{n}cos(\frac{x_i}{\sqrt{i}})$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_10_0.png){:class="fcnplot"}

The contour of the function: 
![{{page.functionname}} Contour]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}} Contour]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_10_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function can be defined on n-dimensional space. 
* The function is unimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-600, 600]$ for $i = 1, ..., n$.

# Global Minima
$f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (0, ..., 0)$

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
% Computes the value of the Griewank benchmark function.
% SCORES = GRIEWANKFCN(X) computes the value of the Griewank's
% function at point X. GRIEWANKFCN accepts a matrix of size M-by-N 
% and returns a vetor SCORES of size M-by-1 in which each row contains the 
% function value for the corresponding row of X.
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
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
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = f(x_1, ..., x_n) = 1 + \sum_{i=1}^{n} \frac{x_i^{2}}{4000} - \prod_{i=1}^{n}cos(\frac{x_i}{\sqrt{i}})
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano
