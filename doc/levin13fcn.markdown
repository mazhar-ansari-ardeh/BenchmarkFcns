---
layout: page
resource: true
title: Levi N. 13 Function
categories: optimization, benchmark
tags: 2-dimensional continuous differentiable non-separable multimodal non-convex
fname: levin13fcn
sname: levin13
functionname: Levi N. 13 Function
modal: multimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
excerpt: The Levi N. 13 function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = sin^2(3\pi x)+(x-1)^2(1+sin^2(3\pi y))+(y-1)^2(1+sin^2(2\pi y))$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-10, 10]$ and $y \in [-10, 10]$ .

# Global Minima
The function has one global minimum $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (1, 1)$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0],
              [1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x, y) = sin^2(3\pi x)+(x-1)^2(1+sin^2(3\pi y))+(y-1)^2(1+sin^2(2\pi y))
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/levy13.html](http://www.sfu.ca/~ssurjano/levy13.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
