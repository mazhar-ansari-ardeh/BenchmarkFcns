---
layout: page
resource: true
title: Gramacy & Lee Function
categories: optimization, benchmark
tags: 1-dimensional continuous multimodal non-convex
fname: gramacyleefcn
sname: gramacylee
functionname: Gramacy & Lee Function
modal: unimodal
dimension: 1-dimensional
excerpt: The Gramacy and Lee function is a multimodal, 1-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x) = \frac{sin(10\pi x)}{2x} + (x-1)^4$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x \in [-0.5, 2.5]$.

# Global Minima
The function has one local minimum at: $f(x^*)=-0.869011134989500$ at $\textbf{x}^{\ast} = 0.548563444114526$.

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
f(x) = \frac{sin(10\pi x)}{2x} + (x-1)^4
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/boha.html](http://www.sfu.ca/~ssurjano/boha.html)
* [http://al-roomi.org/benchmarks/unconstrained/1-dimension/258-gramacy-lee-s-function-no-1](http://al-roomi.org/benchmarks/unconstrained/1-dimension/258-gramacy-lee-s-function-no-1)
