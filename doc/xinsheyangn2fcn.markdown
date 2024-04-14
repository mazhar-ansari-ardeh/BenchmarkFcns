---
layout: page
resource: true
title: Xin-She Yang N. 2 Function
categories: optimization, benchmark
tags: n-dimensional non-separable multimodal non-convex non-differentiable
fname: xinsheyangn2fcn
functionname: Xin-She Yang N. 2 Function
modal: multimodal
dimension: n-dimensional
separable: non-separable
differentiable: non-differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Xin-She Yang N. 2 function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(\mathbf{x})=f(x_1, ..., x_n)=(\sum_{i=1}^{n}|x_i|)exp(-\sum_{i=1}^{n}sin(x_i^2))$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_5.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_6.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_7.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_8.png){:class="fcnplot"}

Two contours of the function are presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-2\pi, 2\pi]$ for $i=1, ..., n$.

# Global Minima
The global minimum $f(\textbf{x}^{\ast})=0$ are located at $\mathbf{x^\ast}=(0, ..., 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf{x})=f(x_1, ..., x_n)=(\sum_{i=1}^{n}|x_i|)exp(-\sum_{i=1}^{n}sin(x_i^2))
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* X. S. Yang, “Test Problems in Optimization,” Engineering Optimization: An Introduction
with Metaheuristic Applications John Wliey & Sons, 2010. [Available Online]:
[http://arxiv.org/abs/1008.0549](http://arxiv.org/abs/1008.0549)
