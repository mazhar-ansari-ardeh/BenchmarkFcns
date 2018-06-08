---
layout: page
resource: true
title: Xin-She Yang Function
categories: optimization, benchmark
tags: n-dimensional separable multimodal non-convex random non-differentiable
fname: xinsheyangn1fcn
functionname: Xin-She Yang Function
modal: multimodal
dimension: n-dimensional
separable: separable
differentiable: non-differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
---


# Mathematical Definition

{%raw%}

$$f(\mathbf x)=f(x_1, ...,x_n)=\sum_{i=1}^{n}\epsilon_i|x_i|^i$$

where $\epsilon$ is a random number that is drawn uniformly from $[0, 1]$
{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

A contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-5, 5]$ for $i=1, ..., n$.

# Global Minima
The global minima $f(\textbf{x}^{\ast})=0$ are located at $\mathbf{x^\ast}=(0, ..., 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf x)=f(x_1, ...,x_n)=\sum_{i=1}^{n}\epsilon_i|x_i|^i
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* X. S. Yang, “Test Problems in Optimization,” Engineering Optimization: An Introduction
with Metaheuristic Applications John Wliey & Sons, 2010. [Available Online]:
[http://arxiv.org/abs/1008.0549](http://arxiv.org/abs/1008.0549)
