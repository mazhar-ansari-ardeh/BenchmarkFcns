---
layout: page
resource: true
title: Holder-Table Function
categories: optimization, benchmark
tags: 2-dimensional continuous non-differentiable non-separable multimodal non-convex
fname: holdertablefcn
functionname: Holder-Table Function
modal: multimodal
dimension: 2-dimensional
differentiable: non-differentiable
separable: non-separable
---

# Mathematical Definition

{%raw%}

$$f(x,y)=-|sin(x)cos(y)exp(|1-\frac{\sqrt{x^2+y^2}}{\pi}|)|$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}

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
The function can be defined on any input domain but it is usually evaluated on $x \in [-10, 10]$ and $y \in [-10, 10]$ .

# Global Minima
The function has four global minima $f(\textbf{x}^{\ast})=-19.2085$ at $\textbf{x}^{\ast} = (\pm 8.05502,\pm 9.66459)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x,y)=-|sin(x)cos(y)exp(|1-\frac{\sqrt{x^2+y^2}}{\pi}|)|
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/holder.html](http://www.sfu.ca/~ssurjano/holder.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
