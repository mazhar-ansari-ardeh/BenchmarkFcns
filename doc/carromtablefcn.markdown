---
layout: page
resource: true
title: Carrom Table Function
categories: optimization, benchmark
tags: 2-dimensional non-separable multimodal non-convex non-differentiable
fname: carromtablefcn
sname: carromtable
functionname: Carrom Table Function
modal: multimodal
dimension: 2-dimensional
separable: non-separable
differentiable: not differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
excerpt: The Carrom Table function is a unimodal, 2-dimensional convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$ f(x,y) = -\frac{1}{30}e^{2 \left |1 - \frac{\sqrt{x^2 + y^2}}{\pi} \right |} \cos^2(x) \cos^2(y) $$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-10, 10]$ for $i=1, 2$.

# Global Minima
The function has a global minimum at $f(\textbf{x}^{\ast})=-24.15681551650653 $ located at $\mathbf{x^\ast}=(\pm 9.646157266348881 , \pm 9.646157266348881)$.

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns) and can be installed from command line with `pip install benchmarkfcns`.  

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0],
                      [1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(x,y) = -\frac{1}{30}e^{2 \left |1 - \frac{\sqrt{x^2 + y^2}}{\pi} \right |} \cos^2(x) \cos^2(y)
{% endhighlight %}

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), [arXiv:1308.4008](arXiv:1308.4008)
