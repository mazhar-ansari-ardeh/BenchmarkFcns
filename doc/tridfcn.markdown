---
layout: page
resource: true
title: Trid Function
categories: optimization, benchmark
tags: n-dimensional continuous differentiable separable unimodal convex
fname: tridfcn
sname: trid
functionname: Trid Function
modal: unimodal
dimension: n-dimensional
differentiable: differentiable
separable: non-separable
convex: is [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Trid function is a unimodal, n-dimensional convex mathematical function widely used for testing optimization algorithms
---


# Mathematical Definition

{%raw%}

$$ f(\mathbf{x})=\sum_{i=1}^{n}(x_i-1)^2-\sum_{i=2}^{n}(x_ix_{i-1}) $$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

<!-- ![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"} -->

A contour of the function is presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-n^2, n^2]$ for $i=1, ..., n$.

# Global Minima
The function has one global minimum $f(\mathbf{x}^{\ast})=-n(n+4)(n-1)/6$ at ${x_i}^{\ast}=i(n+1 - i)$ for $i=1, ..., n$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0, 0],
              [1, 1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\mathbf{x})=\sum_{i=1}^{n}(x_i-1)^2-\sum_{i=2}^{n}(x_ix_{i-1})
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/trid.html](http://www.sfu.ca/~ssurjano/trid.html).
* Adorio, E. P., & Diliman, U. P. MVF - Multivariate Test Functions Library in C for Unconstrained Global Optimization (2005). 
* Global Optimization Test Problems [http://www-optima.amp.i.kyoto-u.ac.jp/member/student/hedar/Hedar_files/TestGO.htm](http://www-optima.amp.i.kyoto-u.ac.jp/member/student/hedar/Hedar_files/TestGO.htm).
