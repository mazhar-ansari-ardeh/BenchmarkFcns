---
layout: page
resource: true
title: Weierstrass Function
categories: optimization, benchmark
tags: n-dimensional continuous non-convex non-differentiable multimodal
fname: weierstrassfcn
sname: weierstrass
functionname: Weierstrass Function
modal: multimodal
dimension: n-dimensional
differentiable: non-differentiable
separable: separable
excerpt: The Weierstrass function is a pathological, n-dimensional, continuous but nowhere differentiable function used for testing optimization algorithms.
---

# Mathematical Definition

{%raw%}

$$
f(\mathbf{x}) = \sum_{i=1}^{n} \left [ \sum_{k=0}^{kmax} a^k \cos \left( 2 \pi b^k (x_i + 0.5) \right) - n \sum_{k=0}^{kmax} a^k \cos(\pi b^k) \right ] 
$$

{%endraw%}

where $a \in (0,1)$, $b$ is a positive odd integer, and $k_{max}$ is a positive integer (commonly $a=0.5$, $b=3$, $k_{max}=20$).

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

# Description and Features
* The function is continuous but nowhere differentiable.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space.
* The function is {{page.modal}}.
* The function is separable.

# Input Domain
The function is usually evaluated on the hypercube $x_i \in [-0.5, 0.5]$ for all $i = 1, ..., n$.

# Global Minimum
The global minimum is located at $\mathbf{x}^* = (0, ..., 0)$, with

$$
f(\mathbf{x}^*) = 0
$$

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
f(\mathbf{x}) = \sum_{i=1}^{n} \left [ \sum_{k=0}^{kmax} a^k \cos \left( 2 \pi b^k (x_i + 0.5) \right) - n \sum_{k=0}^{kmax} a^k \cos(\pi b^k) \right ] 
{% endhighlight %}

# References
* [Weierstrass function - Wikipedia](https://en.wikipedia.org/wiki/Weierstrass_function)
* Yao, X., Liu, Y., & Lin, G. (1999). Evolutionary programming made faster. IEEE Transactions on Evolutionary Computation, 3(2), 82-102.
