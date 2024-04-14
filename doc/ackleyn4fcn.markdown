---
layout: page
author: 'Mazhar Ansari Ardeh'
resource: true
title: Ackley N. 4 Function
categories: optimization, benchmark
tags: n-dimensional non-separable multimodal non-convex differentiable
fname: ackleyn4fcn
functionname: Ackley N. 4 Function
modal: multimodal
dimension: n-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
noplots: 8
nocontour: Two
excerpt: The Ackley N. 4 function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(\textbf{x})=\sum_{i=1}^{n-1}\left( e^{-0.2}\sqrt{x_i^2+x_{i+1}^2} + 3\left( cos(2x_i) + sin(2x_{i+1}) \right) \right)$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

{% for i in (2..page.noplots) %}
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_{{i}}.png){:class="fcnplot"}
{% endfor %}


{%if page.nocontour == 'A' or page.nocontour == 'One' or page.nocontour == 'one'%}
A contour of the function is presented below:
{%else%}
{{page.nocontour}} contours of the function are presented below:
{% endif %}
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-35, 35]$ for $i=1, ..., n$.

# Global Minima
On the 2-dimensional space, the function has one global minima at $f(\textbf{x}^{\ast}) = -4.590101633799122$ located at $\mathbf{x^\ast}=(-1.51, -0.755)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x})=\sum_{i=1}^{n-1}\left( e^{-0.2}\sqrt{x_i^2+x_{i+1}^2} + 3\left( cos(2x_i) + sin(2x_{i+1}) \right) \right)
{% endhighlight %}

# See also: 
* [Ackley Function]({{site.baseurl}}/doc/ackleyfcn)
* [Ackley N. 2 Function]({{site.baseurl}}/doc/ackleyn2fcn)
* [Ackley N. 3 Function]({{site.baseurl}}/doc/ackleyn3fcn)

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)

