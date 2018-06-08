---
layout: page
resource: true
title: Bartels Conn Function
categories: optimization, benchmark
tags: 2-dimensional non-separable multimodal non-convex non-differentiable
fname: bartelsconnfcn
functionname: Bartels Conn Function
modal: multimodal
dimension: 2-dimensional
separable: non-separable
differentiable: non-differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
---

# Mathematical Definition

{%raw%}

$$f(x,y)=|x^2 + y^2 + xy| + |sin(x)| + |cos(y)|$$

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
The function can be defined on any input domain but it is usually evaluated on $x \in [-500, 500]$ and $y \in [-500, 500]$.

# Global Minima
The global minimum $f(\textbf{x}^{\ast})=1$ is located at $\mathbf{x^\ast}=(0, 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x,y)=|x^2 + y^2 + xy| + |sin(x)| + |cos(y)|
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
