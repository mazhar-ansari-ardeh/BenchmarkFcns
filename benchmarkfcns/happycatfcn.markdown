---
layout: page
author: 'Mazhar Ansari Ardeh'
resource: true
title: Happy Cat Function
categories: optimization, benchmark
tags: n-dimensional non-separable multimodal non-convex differentiable parametric
fname: happycatfcn
functionname: Happy Cat Function
modal: multimodal
dimension: n-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
noplots: 4
nocontour: 1
excerpt: The Happy Cat function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$f(\textbf{x})=\left[\left(||\textbf{x}||^2 - n\right)^2\right]^\alpha + \frac{1}{n}\left(\frac{1}{2}||\textbf{x}||^2+\sum_{i=1}^{n}x_i\right)+\frac{1}{2}$$

{%endraw%}

# Plots
For the value of $$\alpha=1/8$$, the function looks as: 

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

{% for i in (2..page.noplots) %}
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_{{i}}.png){:class="fcnplot"}
{% endfor %}


{%if page.nocontour == 'A' or page.nocontour == 'One' or page.nocontour == 'one' or page.nocontour == 1 %}
   A contour of the function is presented below:
{%else%}
   {{page.nocontour}} contours of the function are presented below:
{% endif %}
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}


# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-2, 2]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum at $f(\textbf{x}^{\ast}) = 0$ located at $\mathbf{x^\ast}=(-1, ..., -1)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x})=\left[\left(||\textbf{x}||^2 - n\right)^2\right]^\alpha + \frac{1}{n}\left(\frac{1}{2}||\textbf{x}||^2+\sum_{i=1}^{n}x_i\right)+\frac{1}{2}
{% endhighlight %}

<!--# See also: 
* [Ackley Function]({{site.baseurl}}/benchmarkfcns/ackleyfcn)
* [Ackley N. 2 Function]({{site.baseurl}}/benchmarkfcns/ackleyn2fcn)
* [Ackley N. 3 Function]({{site.baseurl}}/benchmarkfcns/ackleyn3fcn)-->

# Acknowledgement: 
* [Prof Hans-Georg Beyer](https://homepages.fhv.at/hgb/) kindly contributed the source code and literature for this function. 

# References:
* Hans-Georg Beyer and Steffen Finck, HappyCat – A Simple Function Class Where Well-Known Direct Search Algorithms Do Fail, Parallel Problem Solving from Nature - PPSN XII,
pp. 367--376 (2012), [https://doi.org/10.1007/978-3-642-32937-1_37](https://doi.org/10.1007/978-3-642-32937-1_37)

