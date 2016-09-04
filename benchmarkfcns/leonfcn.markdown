---
layout: page
resource: true
title: Leon Function
categories: optimization, benchmark
tags: 2-dimensional, continuous, differentiable, non-separable, unimodal
fname: leonfcn
functionname: Leon Function
modal: unimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
convex: not [convex](https://en.wikipedia.org/wiki/Convex_function)
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

$$f(x, y) = 100(y − x^{3})^2 + (1 − x)^2$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

Contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [0, 10]$ for $i=1, 2$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (1,1)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = 100(y − x^{3})^2 + (1 − x)^2
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* A. Lavi, T. P. Vogel (eds), “Recent Advances in Optimization Techniques,” John Wiley & Sons, 1966
* [http://al-roomi.org/benchmarks/unconstrained/2-dimensions/125-leon-s-function](http://al-roomi.org/benchmarks/unconstrained/2-dimensions/125-leon-s-function)