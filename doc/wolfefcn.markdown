---
layout: page
resource: true
title: Wolfe Function
categories: optimization, benchmark
tags: 3-dimensional continuous differentiable non-separable multimodal non-convex
fname: wolfefcn
functionname: Wolfe Function
modal: multimodal
dimension: 3-dimensional
differentiable: differentiable
separable: non-separable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Wolfe function is a multimodal, 3-dimensional non-convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(x, y, z) = \frac{4}{3}(x^2 + y^2 - xy)^{0.75} + z$$

{%endraw%}

# Description and Features
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [0, 2]$ for $i=1, ..., 3$.

# Global Minima
The global minima $f(\textbf{x}^{\ast})=0$ are located at $\mathbf{x^\ast}=(0, 0, 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y, z) = \frac{4}{3}(x^2 + y^2 - xy)^{0.75} + z
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* H. P. Schwefel, “Numerical Optimization for Computer Models,” John Wiley Sons,
1981.
