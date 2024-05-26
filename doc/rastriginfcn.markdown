---
layout: page
resource: true
title: Rastrigin Function
categories: optimization, benchmark
tags: n-dimensional continuous differentiable separable multimodal convex
fname: rastriginfcn
sname: rastrigin
functionname: Rastrigin Function
modal: multimodal
dimension: n-dimensional
differentiable: differentiable
separable: separable
excerpt: The Rastrigin function is a multimodal, n-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x})=f(x_1, ..., x_n)=10n + \sum_{i=1}^{n}(x_i^2 - 10cos(2\pi x_i))$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_5.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.
* The function is {{page.scalable}}.

# Input Domain
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0, 0],
              [1, 1, 1]]))
{% endhighlight %}

#### MATLAB
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-5.12, 5.12]$ for $i = 1, ..., n$ .

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0 at $\textbf{x}^{\ast} = (0, 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x})=f(x_1, ..., x_n)=10n + \sum_{i=1}^{n}(x_i^2 - 10cos(2\pi x_i))
{% endhighlight %}

# Acknowledgement
Tobias Völk kindly contributed to the correctness of this document. 

# References:
* [http://www.sfu.ca/~ssurjano/rastr.html](http://www.sfu.ca/~ssurjano/rastr.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
