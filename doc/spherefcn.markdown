---
layout: page
resource: true
title: Sphere Function
categories: optimization, benchmark
tags: n-dimensional continuous convex differentiable unimodal separable
fname: spherefcn
excerpt: Sphere function is a unimodal, n-dimensional convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, x_2, ..., x_n) = {\sum_{i=1}^{n} x_i^{2}}.$$

{%endraw%}

# Plots
![Sphere Function]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

The contour of the function: 
![Sphere Function Contour]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function can be defined on n-dimensional space. 
* The function is differentiable.
* The function is separable.
* The function is unimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on the hypercube $x_i \in [-5.12, 5.12]$ for $i = 1..n$.

# Global Minima
$f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (0, ..., 0)$

# Implementation
An implementation of the **Sphere function** with MATLAB is provided below. **Sphere function** can be implemented with a `for` loop that iterates over all the components of the input vector but, MATLAB and Octave have built-in facilities that makes the implementation more efficient and concise.

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
f(\textbf{x}) = f(x_1, x_2, ..., x_n) = {\sum_{i=1}^{n} x_i^{2}}
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano/spheref.html
* https://en.wikipedia.org/wiki/Test_functions_for_optimization
