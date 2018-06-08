---
layout: page
author: 'Mazhar Ansari Ardeh'
resource: true
title: Bird Function
categories: optimization, benchmark
tags: 2-dimensional non-separable multimodal non-convex differentiable
fname: birdfcn
functionname: Bird Function
modal: multimodal
dimension: 2-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
nocontour: Two
description: Bird function is a test function for optimization algorithms. 
---


# Mathematical Definition

{%raw%}

$$f(x, y) = sin(x)e^{(1-cos(y))^2}+cos(y)e^{(1-sin(x))^2}+(x-y)^2$$

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

{%if page.nocontour == 'A' or page.nocontour == 'One' or page.nocontour == 'one'%}
A contour of the function is presented below:
{%else%}
{{page.nocontour}} contours of the function are presented below:
{% endif %}
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-2\pi, 2\pi]$ for $i=1, 2$.

# Global Minima
The function has two global minima at $f(\textbf{x}^{\ast}) = -106.764537$ located at $\mathbf{x^\ast}=(4.70104, 3.15294)$ and $\mathbf{x^\ast}=(-1.58214, -3.13024)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = sin(x)e^{(1-cos(y))^2}+cos(y)e^{(1-sin(x))^2}+(x-y)^2
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* S. K. Mishra, “Global Optimization By Differential Evolution and Particle Swarm
Methods: Evaluation On Some Benchmark Functions,” Munich Research Papers in
Economics, Available Online: [http://mpra.ub.uni-muenchen.de/1005/](http://mpra.ub.uni-muenchen.de/1005/).
