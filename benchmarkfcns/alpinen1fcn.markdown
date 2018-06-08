---
layout: page
resource: true
title: Alpine N. 1 Function
categories: optimization, benchmark
tags: n-dimensional non-separable multimodal non-convex differentiable
fname: alpinen1fcn
functionname: Alpine N. 1 Function
modal: multimodal
dimension: n-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
---

# Mathematical Definition

{%raw%}

$$f(\mathbf x)=f(x_1, ..., x_n) = \sum_{i=1}^{n}|x_i sin(x_i)+0.1x_i|$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_5.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_6.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_7.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_8.png){:class="fcnplot"}

Two contours of the function are presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any positive input domain but it is usually evaluated on $x_i \in [0, 10]$ for $i=1, ..., n$.

# Global Minima
The function has a global minimum  $f(\textbf{x}^{\ast})=0$ located at $\mathbf{x^\ast}=(0, ..., 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf x)=f(x_1, ..., x_n) = \sum{i=1}^{n}|x_i sin(x_i)+0.1x_i|
{% endhighlight %}

# See Also:
* [Alpine N. 2 Function]({{site.baseurl}}/benchmarkfcns/alpinen2fcn)

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* M. Clerc, “The Swarm and the Queen, Towards a Deterministic and Adaptive Particle
Swarm Optimization, ” IEEE Congress on Evolutionary Computation, Washington
DC, USA, pp. 1951-1957, 1999.
