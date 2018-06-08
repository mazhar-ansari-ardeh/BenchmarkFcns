---
layout: page
author: 'Mazhar Ansari Ardeh'
resource: true
title: Bohachevsky N. 2 Function
categories: optimization, benchmark
tags: 2-dimensional non-separable multimodal non-convex differentiable
fname: bohachevskyn2fcn
functionname: Bohachevsky N. 2 Function
modal: multimodal
dimension: 2-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
nocontour: One
description: Bohachevskyn N. 2 function is a 2-dimensional, non-separable, multimodal, non-convex, differentiable, continuous, test function for optimization algorithms. 
---

# Mathematical Definition

{%raw%}

$$f(x, y)=x^2 + 2y^2 -0.3cos(3\pi x)cos(4\pi y)+0.3$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

{%if page.nocontour == 'A' or page.nocontour == 'One' or page.nocontour == 'one'%}
A contour of the function is presented below:
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}
{%else%}
{{page.nocontour}} contours of the function are presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}
{% endif %}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-100, 100]$ for $i=1, 2$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast}) = 0$ located at $\mathbf{x^\ast}=(0, 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y)=x^2 + 2y^2 -0.3cos(3\pi x)cos(4\pi y)+0.3
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* I. O. Bohachevsky, M. E. Johnson, M. L. Stein, “General Simulated Annealing for
Function Optimization,” Technometrics, vol. 28, no. 3, pp. 209-217, 1986.
