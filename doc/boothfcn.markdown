---
layout: page
resource: true
title: Booth Function
categories: optimization, benchmark
tags: 2-dimensional continuous convex differentiable non-separable unimodal convex
fname: boothfcn
sname: booth
functionname: Booth Function
modal: unimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
excerpt: The Booth function is a unimodal, 2-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x,y)=(x+2y-7)^2+(2x+y-5)^2$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.scalable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-10, 10]$ for all $i = 1,2$.

# Global Minima
The function has one global minimum at: $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (1,3)$.

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
f(x,y)=(x+2y-7)^2+(2x+y-5)^2
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/booth.html](http://www.sfu.ca/~ssurjano/booth.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
