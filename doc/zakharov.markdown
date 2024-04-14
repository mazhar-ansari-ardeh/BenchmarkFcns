---
layout: page
resource: true
title: Zakharov Function
categories: optimization, benchmark
tags: continuous convex n-dimensional unimodal
fname: zakharovfcn
functionname: Zakharov Function
excerpt: The Zakharov function is a unimodal, n-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x})=f(x_1, ..., x_n)=\sum_{i=1}^n x_i^{2}+(\sum_{i=1}^n 0.5ix_i)^2 + (\sum_{i=1}^n 0.5ix_i)^4$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

The contour of the function: 
![{{ page.functionname }}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function can be defined on n-dimensional space. 
* The function is unimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on the hypercube $x_i \in [-5, 10]$ for $i = 1..n$.

# Global Minima
$f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (0, ..., 0)$

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 
{% highlight MATLAB%}
% Computes the value of Zakharov benchmark function.
% SCORES = ZAKHAROVFCN(X) computes the value of the Zakharov function at 
% point X. ZAKHAROVFCN accepts a matrix of size M-by-N and returns a vetor 
% SCORES of size M-by-1 in which each row contains the function value for
% each row of X.
% 
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function scores = zakharovfcn(x)

    n = size(x, 2);
    comp1 = 0;
    comp2 = 0;
    
    for i = 1:n
        comp1 = comp1 + (x(:, i) .^ 2);
        comp2 = comp2 + (0.5 * i * x(:, i));
    end
     
    scores = comp1 + (comp2 .^ 2) + (comp2 .^ 4);
end
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x})=f(x_1, ..., x_n)=\sum_{i=1}^n x_i^{2}+(\sum_{i=1}^n 0.5ix_i)^2 + (\sum_{i=1}^n 0.5ix_i)^4
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano/zakharov.html
