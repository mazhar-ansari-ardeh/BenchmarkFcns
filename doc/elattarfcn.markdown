---
layout: page
resource: true
title: El-Attar-Vidyasagar-Dutta Function
categories: optimization, benchmark
tags: 2-dimensional continuous multimodal non-convex differentiable
fname: elattarfcn
functionname: El-Attar-Vidyasagar-Dutta Function
modal: multimodal
dimension: 2-dimensional
excerpt: The El-Attar-Vidyasagar-Dutta Function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = (x^2 + y - 10)^2 + (x + y^2 - 7)^2 + (x^2 + y^3 - 1)^2$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}


# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-500, 500]$ for all $i = 1, 2$.

# Global Minima
The function has one global minimum at: $f({x}^{\ast}, {y}^{\ast})=0$ at $({x}^{\ast}, {y}^{\ast}) = (3.4091868222,-2.1714330361)$.

# Implementation
## Python
For Python, the function is implemented in the [benchmarkfcns package](github.com/mazhar-ansari-ardeh/BenchmarkFcns) and can be installed from command line with `pip install benchmarkfcns`.  

{%highlight Python%}
from benchmarkfcns import elattar

print(elattar([[3.4091868222,−2.1714330361]]))
{% endhighlight %}

## MATLAB
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
$$f(x, y) = (x^2 + y - 10)^2 + (x + y^2 - 7)^2 + (x^2 + y^3 - 1)^2$$
{% endhighlight %}


# References:
* R. A. El-Attar, M. Vidyasagar, S. R. K. Dutta, An Algorithm for II-norm Minimization With Application to Nonlinear II-approximation, SIAM Journal on Numverical Analysis, vol. 16, no. 1, pp. 70-86, 1979.
