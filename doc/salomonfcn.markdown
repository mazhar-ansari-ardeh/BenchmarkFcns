---
layout: page
resource: true
title: Salomon Function
categories: optimization, benchmark
tags: n-dimensional continuous differentiable non-separable multimodal non-convex
fname: salomonfcn
sname: salomon
functionname: Salomon Function
modal: multimodal
dimension: n-dimensional
differentiable: differentiable
separable: non-separable
convex: not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Salomon function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\mathbf x)=f(x_1, ..., x_n)=1-cos(2\pi\sqrt{\sum_{i=1}^{D}x_i^2})+0.1\sqrt{\sum_{i=1}^{D}x_i^2}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

Contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-100, 100]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (0, ..., 0)$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0, 0],
              [1, 1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf x)=f(x_1, ..., x_n)=1-cos(2\pi\sqrt{\sum_{i=1}^{D}x_i^2})+0.1\sqrt{\sum_{i=1}^{D}x_i^2}
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](https://arxiv.org/abs/1308.4008)
* [http://profesores.elo.utfsm.cl/~tarredondo/info/soft-comp/functions/node12.html](http://profesores.elo.utfsm.cl/~tarredondo/info/soft-comp/functions/node12.html)
* R. Salomon, “Re-evaluating Genetic Algorithm Performance Under Corodinate Rotation
of Benchmark Functions: A Survey of Some Theoretical and Practical Aspects of
Genetic Algorithms,” BioSystems, vol. 39, no. 3, pp. 263-278, 1996.
