---
layout: page
resource: true
title: Biggs EXP02 Function
categories: optimization, benchmark
tags: 2-dimensional continuous non-convex differentiable non-separable multimodal non-scalable
fname: biggsexp02fcn
sname: biggsexp02
functionname: Biggs EXP02 Function
modal: multimodal
dimension: 2-dimensional
differentiable: differentiable
separable: non-separable
scalable: non-scalable
excerpt: The Biggs EXP02 function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x) = \sum_{i=1}^{10} \left( e^{-t_i x_1} - 5 e^{-t_i x_2} - \left(e^{-t_i} - 5 e^{-10 t_i}\right) \right)^2$$

where $t_i = 0.1 \cdot i$.

{%endraw%}

Biggs EXP02 is a well-known nonlinear least squares benchmark problem used primarily in numerical optimization to test the efficiency and robustness of various algorithms, such as the Levenberg-Marquardt or Gauss-Newton methods. It simulates a "sum of exponentials" fitting problem. These are notoriously tricky because they can be "ill-conditioned"—meaning small changes in the parameters can lead to very similar curves, making it hard for an optimizer to find the exact bottom of the "valley."

The function belongs to a family of problems (Biggs EXP2 through EXP6) originally proposed by M.C. Biggs in the 1970s to push the limits of optimization software.

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is non-convex.
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.
* The function is {{page.differentiable}}.
* The function is {{page.separable}}.
* The function is {{page.scalable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_1, x_2 \in [0, 20]$.

# Global Minima
The function has one global minimum at: $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (1, 10)$.

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
f(x) = \sum_{i=1}^{10} \left( e^{-t_i x_1} - 5 e^{-t_i x_2} - \left(e^{-t_i} - 5 e^{-10 t_i}\right) \right)^2
{% endhighlight %}

# References:
* 