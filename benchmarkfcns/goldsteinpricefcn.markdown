---
layout: page
resource: true
title: Goldstein-Price Function
categories: optimization, benchmark
tags: 2-dimensional continuous differentiable non-separable multimodal non-convex
fname: goldsteinpricefcn
functionname: Goldstein-Price Function
modal: multimodal
dimension: 2-dimensional
differentiable: differentiable
scalable: non-scalable
excerpt: The Goldstein-Price function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x,y)=[1 + (x + y + 1)^2(19 − 14x+3x^2− 14y + 6xy + 3y^2)][30 + (2x − 3y)^2(18 − 32x + 12x^2 + 4y − 36xy + 27y^2)]$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.
* The function is {{page.scalable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-2, 2]$ and $y \in [-2, 2]$ .

# Global Minima
The function has four global minima $f(\textbf{x}^{\ast})=3$ at $\textbf{x}^{\ast} = (0, -1)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x,y)=[1 + (x + y + 1)^2(19 − 14x+3x^2− 14y + 6xy + 3y^2)][30 + (2x − 3y)^2(18 − 32x + 12x^2 + 4y − 36xy + 27y^2)]
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/goldpr.html](http://www.sfu.ca/~ssurjano/goldpr.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
