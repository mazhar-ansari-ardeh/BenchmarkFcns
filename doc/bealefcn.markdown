---
layout: page
resource: true
title: Beale Function
categories: optimization, benchmark
tags: 2-dimensional continuous multimodal non-convex
fname: bealefcn
functionname: Beale Function
modal: multimodal
dimension: 2-dimensional
excerpt: The Beale function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = (1.5-x+xy)^2+(2.25-x+xy^2)^2+(2.625-x+xy^3)^2$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-4.5, 4.5]$ for all $i = 1, 2$.

# Global Minima
The function has one global minimum at: $f(x^*)=0$ at $\textbf{x}^{\ast} = (3, 0.5)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = (1.5-x+xy)^2+(2.25-x+xy^2)^2+(2.625-x+xy^3)^2
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/ackley.html](http://www.sfu.ca/~ssurjano/ackley.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* [http://www-optima.amp.i.kyoto-u.ac.jp/member/student/hedar/Hedar_files/TestGO_files/Page288.htm](http://www-optima.amp.i.kyoto-u.ac.jp/member/student/hedar/Hedar_files/TestGO_files/Page288.htm)
