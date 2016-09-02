---
layout: page
resource: true
title: Quartic Function
categories: optimization, benchmark
tags: n-dimensional, continuous, differentiable, separable, multimodal, random
fname: quarticfcn
functionname: Quartic Function
modal: multimodal
dimension: n-dimensional
differentiable: differentiable
separable: separable
convex: not convex
---
<head>
	<script type="text/x-mathjax-config">
	  MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});
	</script>
	<script type="text/javascript" async
	  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_CHTML">
	</script>
</head>


# Mathematical Definition

{%raw%}

$$f(\mathbf{x})=f(x_1,...,x_n)=\sum_{i=1}^{n}ix_i^4+\text{random}[0,1)$$
{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

Contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is {{page.convex}} [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-1.28, 1.28]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0 + \it\text{random noise}$ at $\textbf{x}^{\ast} = (0, ..., 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf{x})=f(x_1,...,x_n)=\sum_{i=1}^{n}ix_i^4+\text{random}[0,1)
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* [http://www.cs.unm.edu/~neal.holts/dga/benchmarkFunction/quartic.html](http://www.cs.unm.edu/~neal.holts/dga/benchmarkFunction/quartic.html)
* R. Storn, K. Price, “Differntial Evolution - A Simple and Efficient Adaptive Scheme
for Global Optimization over Continuous Spaces,” Technical Report no. TR-95-012,
International Computer Science Institute, Berkeley, CA, 1996. [Available Online]:
(R. Storn, K. Price, “Differntial Evolution - A Simple and Efficient Adaptive Scheme
for Global Optimization over Continuous Spaces,” Technical Report no. TR-95-012,
International Computer Science Institute, Berkeley, CA, 1996. [Available Online] :
[http://www1.icsi.berkeley.edu/~storn/TR-95-012.pdf](http://www1.icsi.berkeley.edu/~storn/TR-95-012.pdf)