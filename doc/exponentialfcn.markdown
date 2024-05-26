---
layout: page
resource: true
title: Exponential Function
categories: optimization, benchmark
tags: n-dimensional continuous differentiable non-separable unimodal convex
fname: exponentialfcn
sname: exponential
functionname: Exponential Function
modal: unimodal
dimension: n-dimensional
differentiable: differentiable
separable: non-separable
convex: is [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Exponential function is a unimodal, n-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\mathbf{x})=f(x_1, ..., x_n)=-exp(-0.5\sum_{i=1}^n{x_i^2})$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

A contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-1, 1]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=$ at $\mathbf{x^\ast}=0$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0, 0],
              [1, 1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf{x})=f(x_1, ..., x_n)=-exp(-0.5\sum_{i=1}^n{x_i^2})
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* S. Rahnamyan, H. R. Tizhoosh, N. M. M. Salama, “Opposition-Based Differential
Evolution (ODE) with Variable Jumping Rate,” IEEE Sympousim Foundations Computation
Intelligence, Honolulu, HI, pp. 81-88, 2007.
