---
layout: page
resource: true
title: Gramacy & Lee Function
categories: optimization, benchmark
tags: 1-dimensional, continuous, unimodal
fname: gramacyleefcn
functionname: Gramacy & Lee Function
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

$$f(x) = \frac{sin(10\pi x)}{2x} + (x-1)^4$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on 1-dimensional space. 
* The function is unimodal.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-0.5, 2.5]$.

# Global Minima
The function has four local minima at: $f(x^*)=-0.869011134989500$ at $\textbf{x}^{\ast} = 0.548563444114526$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x) = \frac{sin(10\pi x)}{2x} + (x-1)^4
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/boha.html](http://www.sfu.ca/~ssurjano/boha.html)
* [http://al-roomi.org/benchmarks/unconstrained/1-dimension/258-gramacy-lee-s-function-no-1](http://al-roomi.org/benchmarks/unconstrained/1-dimension/258-gramacy-lee-s-function-no-1)