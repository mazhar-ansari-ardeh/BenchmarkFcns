---
layout: page
resource: true
title: Egg Crate Function
categories: optimization, benchmark
tags: 2-dimensional continuous differentiable separable multimodal non-convex
fname: eggcratefcn
functionname: Egg Crate Function
modal: multimodal
dimension: 2-dimensional
differentiable: differentiable
separable: separable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Egg Crate function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x,y)=x^2 + y^2 + 25(sin^2(x) + sin^2(y))$$

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
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-5, 5]$ for $i=1, 2$.

# Global Minima
The global minimum $f(\textbf{x}^{\ast})=0$ is located at $\mathbf{x^\ast}=(0, 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x,y)=x^2 + y^2 + 25(sin^2(x) + sin^2(y))
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* [http://al-roomi.org/benchmarks/unconstrained/2-dimensions/122-egg-crate-function](http://al-roomi.org/benchmarks/unconstrained/2-dimensions/122-egg-crate-function)
* Chawdhry, P. K., Roy, R., & Pant, R. K. (2012). Soft Computing in Engineering Design and Manufacturing. London: Springer Science & Business Media.
* Yang, X.S. (2008). Nature-Inspired Metaheuristic Algorithms, Luniver Press.
