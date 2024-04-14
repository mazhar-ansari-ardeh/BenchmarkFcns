---
layout: page
resource: true
title: Easom Function
categories: optimization, benchmark
tags: 2-dimensional continuous differentiable separable multimodal non-convex
fname: easomfcn
functionname: Easom Function
modal: multimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
scalable: non-scalable
excerpt: The Easom function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x,y)=−cos(x)cos(y) exp(−(x − \pi)^2−(y − \pi)^2)$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_4.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.
* The function is {{page.scalable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-100, 100]$ and $y \in [-100, 100]$ .

# Global Minima
The function has four global minima $f(x^{\ast}, y^{\ast})=-1$ at $(x^{\ast}, y^{\ast}) = (\pi,\pi)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x,y)=−cos(x)cos(y) exp(−(x − \pi)^2−(y − \pi)^2)
{% endhighlight %}

# Acknowledgement
Tobias Völk kindly contributed to the correctness of this document. 


# References:
* [http://www.sfu.ca/~ssurjano/easom.html](http://www.sfu.ca/~ssurjano/easom.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
* [http://www-optima.amp.i.kyoto-u.ac.jp/member/student/hedar/Hedar_files/TestGO_files/Page1361.htm](http://www-optima.amp.i.kyoto-u.ac.jp/member/student/hedar/Hedar_files/TestGO_files/Page1361.htm)
