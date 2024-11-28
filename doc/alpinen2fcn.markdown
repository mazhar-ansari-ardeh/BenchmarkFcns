---
layout: page
resource: true
title: Alpine N. 2 Function
categories: optimization, benchmark
tags: n-dimensional non-separable multimodal non-convex differentiable
fname: alpinen2fcn
sname: alpine2
functionname: Alpine N. 2 Function
modal: multimodal
dimension: n-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Alpine N. 2 function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\mathbf x)=f(x_1, ..., x_n) = \prod_{i=1}^{n}\sqrt{x_i}sin(x_i)$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

A contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any positive input domain but it is usually evaluated on $x_i \in [0, 10]$ for $i=1, ..., n$.

# Global Minima
The function was devised By Clerc as a maximization problem and hence, the orginial paper gave  $f(\textbf{x}^{\ast})=2.808^n$, 
located at $\mathbf{x^\ast}=(7.917, ..., 7.917)$, as its global maximum. The function can be used for minization by negating its 
value.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns) and can be installed from command line with `pip install benchmarkfcns`.  

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
f(\mathbf x)=f(x_1, ..., x_n) = \prod_{i=1}^{n}\sqrt{x_i}sin(x_i)
{% endhighlight %}

# See Also:
* [Alpine N. 1 Function]({{site.baseurl}}/doc/alpinen1fcn)

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](https://arxiv.org/abs/1308.4008)
* M. Clerc, “The Swarm and the Queen, Towards a Deterministic and Adaptive Particle
Swarm Optimization, ” IEEE Congress on Evolutionary Computation, Washington
DC, USA, pp. 1951-1957, 1999.
