---
layout: page
resource: true
title: Powell Sum Function
categories: optimization, benchmark
tags: n-dimensional continuous non-differentiable separable unimodal convex
fname: powellsumfcn
functionname: Powell Sum Function
modal: unimodal
dimension: n-dimensional
differentiable: non-differentiable
separable: separable
convex: is [convex](https://en.wikipedia.org/wiki/Convex_function)
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

$$f(\mathbf{x})=f(x_1, ..., x_n)=\sum_{i=1}^{n}|x_i|^{i+1}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

A contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-1, 1]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum $f(\mathbf{x}^{\ast})=0$ at $\mathbf{x}^{\ast} = 0$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf{x})=f(x_1, ..., x_n)=\sum_{i=1}^{n}|x_i|^{i+1}
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* S. Rahnamyan, H. R. Tizhoosh, N. M. M. Salama, “A Novel Population Initialization
Method for Accelerating Evolutionary Algorithms,” Computers and Mathematics with
Applications, vol. 53, no. 10, pp. 1605-1614, 2007.
* Mukhopadhyay, Sumitra; Das, Soumyadip, (2016), A System on Chip Development of Customizable GA Architecture for Real Parameter Optimization Problem, 
in Handbook of Research on Natural Computing for Optimization Problems, IGI Global. 