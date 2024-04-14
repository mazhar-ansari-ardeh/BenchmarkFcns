---
layout: page
resource: true
title: Deckkers-Aarts Function
categories: optimization, benchmark
tags: 2-dimensional continuous differentiable non-separable multimodal non-convex
fname: deckkersaartsfcn
functionname: Deckkers-Aarts Function
modal: multimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Deckkers-Aarts function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = 10^5x^2 + y^2 -(x^2 + y^2)^2 + 10^{-5}(x^2 + y^2)^4$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

A contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-20, 20]$ for $i=1, ..., n$.

# Global Minima
The global minima $f(\textbf{x}^{\ast})=-24771.09375$ are located at $\mathbf{x^\ast}=(0, \pm 15)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = 10^5x^2 + y^2 -(x^2 + y^2)^2 + 10^{-5}(x^2 + y^2)^4
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* M. M. Ali, C. Khompatraporn, Z. B. Zabinsky, “A Numerical Evaluation of Several
Stochastic Algorithms on Selected Continuous Global Optimization Test Problems,”
Journal of Global Optimization, vol. 31, pp. 635-672, 2005.
