---
layout: page
resource: true
title: Ackley N. 2 Function
categories: optimization, benchmark
tags: 2-dimensional non-separable unimodal convex differentiable
fname: ackleyn2fcn
functionname: Ackley N. 2 Function
modal: unimodal
dimension: 2-dimensional
separable: non-separable
differentiable: differentiable
convex: is [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Ackley N. 2 function is a unimodal, 2-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = -200e^{-0.2\sqrt{x^2 + y^2}}$$

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
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-32, 32]$ for $i=1, 2$.

# Global Minima
The function has a global minimum at $f(\textbf{x}^{\ast})=-200$ located at $\mathbf{x^\ast}=(0, 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = -200e^{-0.2\sqrt{x^2 + y^2}}
{% endhighlight %}

# See Also:
* [Ackley Function]({{site.baseurl}}/benchmarkfcns/ackleyfcn)
* [Ackley N. 3 Function]({{site.baseurl}}/benchmarkfcns/ackleyn3fcn)
* [Ackley N. 4 Function]({{site.baseurl}}/benchmarkfcns/ackleyn4fcn)

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* D. H. Ackley, “A Connectionist Machine for Genetic Hill-Climbing,” Kluwer, 1987.
