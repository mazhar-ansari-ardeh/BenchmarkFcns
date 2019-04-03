---
layout: page
resource: true
title: Brown Function
categories: optimization, benchmark
tags: n-dimensional non-separable unimodal convex differentiable
fname: brownfcn
functionname: Brown Function
modal: unimodal
dimension: n-dimensional
separable: non-separable
differentiable: differentiable
convex: is [convex](https://en.wikipedia.org/wiki/Convex_function)
nocontour: Two
excerpt: The Brown function is a unimodal, n-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = \sum_{i=1}^{n-1}(x_i^2)^{(x_{i+1}^{2}+1)}+(x_{i+1}^2)^{(x_{i}^{2}+1)}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}


![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_5.png){:class="fcnplot"}


![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_6.png){:class="fcnplot"}


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
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-1, 4]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum at $f(\textbf{x}^{\ast})= 0$ located at $\mathbf{x^\ast}=\textbf{0}$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = \sum_{i=1}^{n-1}(x_i^2)^{(x_{i+1}^{2}+1)}+(x_{i+1}^2)^{(x_{i}^{2}+1)}
{% endhighlight %}


# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
