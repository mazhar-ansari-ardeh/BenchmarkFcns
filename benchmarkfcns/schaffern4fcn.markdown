---
layout: page
resource: true
title: Schaffer N. 4 Function
categories: optimization, benchmark
tags: 2-dimensional, continuous, differentiable, non-separable, unimodal, non-scalable
fname: schaffern4fcn
functionname: Schaffer N. 4 Function
modal: unimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
scalable: non-scalable
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

$$f(x, y)=0.5 + \frac{cos(sin(|x^2-y^2|))-0.5}{(1+0.001(x^2+y^2))^2}$$
{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_5.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_6.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_7.png){:class="fcnplot"}
Two contours of the function are as presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.
* The function is {{page.scalable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-100, 100]$ for $i=1, 2$.

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0.292579$ at $\textbf{x}^{\ast} = (0, 1.253115)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y)=0.5 + \frac{cos(sin(|x^2-y^2|))-0.5}{(1+0.001(x^2+y^2))^2}
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/schaffer2.html](http://www.sfu.ca/~ssurjano/schaffer2.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)