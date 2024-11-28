---
layout: page
resource: true
title: Rosenbrock Function
categories: optimization, benchmark
tags: n-dimensional continuous differentiable non-separable multimodal non-convex
fname: rosenbrockfcn
sname: rosenbrock
functionname: Rosenbrock Function
modal: multimodal
dimension: n-dimensional
differentiable: differentiable
separable: non-separable
excerpt: The Rosenbrock function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x})=f(x_1, ..., x_n)=\sum_{i=1}^{n-1}[b (x_{i+1} - x_i^2)^ 2 + (a - x_i)^2]$$
{%endraw%}
In this formula, the parameters $a$ and $b$ are constants and are generally set to $a=1$ and $b=100$.

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-5, 10]$ for $i=1, ..., n$ .

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (1, ..., 1)$.

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
f(\textbf{x})=f(x_1, ..., x_n)=\sum_{i=1}^{n-1}[b (x_{i+1} - x_i^2)^ 2 + (a - x_i)^2]
{% endhighlight %}

# Acknowledgement
Tobias Völk kindly contributed to the correctness of this document. 

# References:
* [http://www.sfu.ca/~ssurjano/rosen.html](http://www.sfu.ca/~ssurjano/rosen.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](https://arxiv.org/abs/1308.4008)
