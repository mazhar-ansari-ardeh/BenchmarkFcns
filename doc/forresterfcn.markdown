---
layout: page
resource: true
title: Forrester Function
categories: optimization, benchmark
tags: 1-dimensional continuous multimodal non-convex
fname: forresterfcn
sname: forrester
functionname: Forrester Function
modal: unimodal
dimension: 1-dimensional
excerpt: The Forrester function is a multimodal, 1-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x)= (6x - 2)^{2}sin(12x - 4)$$

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
The function has one local minimum at: $f(x^*)=-6.0207$ at $\textbf{x}^{\ast} = 0.757249$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0],
              [1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x)= (6x - 2)^{2}sin(12x - 4)
{% endhighlight %}

# References:
* [https://www.sfu.ca/~ssurjano/forretal08.html](https://www.sfu.ca/~ssurjano/forretal08.html)
* Forrester, A., Sobester, A., & Keane, A. (2008). Engineering design via surrogate modelling: a practical guide. Wiley.
