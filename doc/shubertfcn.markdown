---
layout: page
resource: true
title: Shubert Function
categories: optimization, benchmark
tags: n-dimensional continuous differentiable non-separable multimodal non-convex
fname: shubertfcn
sname: shubert
functionname: Shubert Function
modal: multimodal
dimension: n-dimensional
differentiable: differentiable
separable: non-separable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Shubert function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(\mathbf{x})=f(x_1, ...,x_n)=\prod_{i=1}^{n}{\left(\sum_{j=1}^5{ cos((j+1)x_i+j)}\right)}$$

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

Two contours of the function are presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-10, 10]$ for $i=1, ..., n$.

# Global Minima
The function has 18 global minima $f(\textbf{x}^{\ast})\approx-186.7309$.

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
f(\mathbf{x})=f(x_1, ...,x_n)=\prod_{i=1}^{n}{\left(\sum_{j=1}^5{ cos((j+1)x_i+j)}\right)}
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](https://arxiv.org/abs/1308.4008)
* E. P. Adorio, U. P. Dilman, “MVF - Multivariate Test Function Library
in C for Unconstrained Global Optimization Methods,” [Available Online]:
[http://www.geocities.ws/eadorio/mvf.pdf](http://www.geocities.ws/eadorio/mvf.pdf)
