---
layout: page
resource: true
title: Adjiman Function
categories: optimization, benchmark
tags: 2-dimensional non-separable multimodal non-convex differentiable
fname: adjimanfcn
functionname: Adjiman Function
modal: multimodal
dimension: 2-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
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

$$f(x, y)=cos(x)sin(y) - \frac{x}{y^2+1}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_5.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_6.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_7.png){:class="fcnplot"}

Two contours of the function are presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-1, 2]$ and $x \in [-1, 1]$.

# Global Minima
On the on $x \in [-1, 2]$ and $x \in [-1, 1]$ cube, the global minimum $f(\textbf{x}^{\ast})=-2.02181$ is located at $\mathbf{x^\ast}=(0, ..., 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y)=cos(x)sin(y) - \frac{x}{y^2+1}
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* C. S. Adjiman, S. Sallwig, C. A. Flouda, A. Neumaier, "A Global Optimization
Method, aBB for General Twice-Differentiable NLPs-1, Theoretical Advances," Computers
Chemical Engineering, vol. 22, no. 9, pp. 1137-1158, 1998.
* Qing, A., "Differential Evolution: Fundamentals and Applications in Electrical Engineering", Wiley, 2009.
[https://books.google.com/books?id=Pp-SHz6dIJ0C](https://books.google.com/books?id=Pp-SHz6dIJ0C)