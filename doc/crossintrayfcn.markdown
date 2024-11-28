---
layout: page
resource: true
title: Cross-in-Tray Function
categories: optimization, benchmark
tags: 2-dimensional continuous non-differentiable non-separable multimodal non-convex
fname: crossintrayfcn
sname: crossintray
functionname: Cross-in-Tray Function
modal: multimodal
dimension: 2-dimensional
differentiable: non-differentiable
excerpt: The Cross-in-Tray function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x,y)=-0.0001(|sin(x)sin(y)exp(|100-\frac{\sqrt{x^2+y^2}}{\pi}|)|+1)^{0.1}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.
* The function is {{page.scalable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-10, 10]$ and $y \in [-10, 10]$ .

# Global Minima
The function has four global minima $f(\textbf{x}^{\ast})=-2.06261218$ at $\textbf{x}^{\ast} = (\pm1.349406685353340,\pm1.349406608602084)$.

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
f(x,y)=-0.0001(|sin(x)sin(y)exp(|100-\frac{\sqrt{x^2+y^2}}{\pi}|)|+1)^{0.1}
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/crossit.html](http://www.sfu.ca/~ssurjano/crossit.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](https://arxiv.org/abs/1308.4008)
