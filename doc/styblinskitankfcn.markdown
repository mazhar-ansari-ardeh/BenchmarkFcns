---
layout: page
resource: true
title: Styblinski-Tank Function
categories: optimization, benchmark
tags: n-dimensional continuous multimodal non-convex
fname: styblinskitankfcn
functionname: Styblinski-Tank Function
modal: multimodal
dimension: n-dimensional
excerpt: The Styblinski-Tank function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, ..., x_n)= \frac{1}{2}\sum_{i=1}^{n} (x_i^4 -16x_i^2+5x_i)$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-5, 5]$ for all $i = 1,...,n$.

# Global Minima
The function has one global minimum at: $f(x^*)=-39.16599\textbf{n}$ at $\textbf{x}^{\ast} = (-2.903534, ..., -2.903534)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = f(x_1, ..., x_n)= \frac{1}{2}\sum_{i=1}^{n} (x_i^4 -16x_i^2+5x_i)
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/stybtang.html](http://www.sfu.ca/~ssurjano/stybtang.html)
