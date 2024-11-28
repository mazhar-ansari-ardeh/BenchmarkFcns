---
layout: page
resource: true
title: Schaffer N. 3 Function
categories: optimization, benchmark
tags: 2-dimensional continuous differentiable non-convex unimodal non-separable non-convex
fname: schaffern3fcn
sname: schaffer3
functionname: Schaffer N. 3 Function
modal: unimodal
dimension: 2-dimensional
differentiable: differentiable
separable: not separable
convex: not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Schaffer N. 3 function is a unimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y)=0.5 + \frac{sin^2(cos(|x^2-y^2|))-0.5}{(1+0.001(x^2+y^2))^2}$$
{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_5.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_6.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_7.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_8.png){:class="fcnplot"}
Two contours of the function are as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is {{page.convex}}
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-100, 100]$ for $i=1, 2$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0.00156685$ at $\textbf{x}^{\ast} = (0, 1.253115)$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0],
              [1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y)=0.5 + \frac{sin^2(cos(|x^2-y^2|))-0.5}{(1+0.001(x^2+y^2))^2}
{% endhighlight %}

# References:
* S. K. Mishra, “Some New Test Functions For Global Optimization And
Performance of Repulsive Particle Swarm Method,” [Available Online]: [http://mpra.ub.uni-muenchen.de/2718/](http://mpra.ub.uni-muenchen.de/2718/)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](https://arxiv.org/abs/1308.4008)
