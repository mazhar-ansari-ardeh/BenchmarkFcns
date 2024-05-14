---
layout: page
resource: true
title: Ackley N. 3 Function
categories: optimization, benchmark
tags: 2-dimensional non-separable multimodal non-convex differentiable
fname: ackleyn3fcn
sname: ackley3
functionname: Ackley N. 3 Function
modal: multimodal
dimension: 2-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
nocontour: Two
excerpt: The Ackley N. 3 function is a multimodal, 2-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(x, y) = -200e^{-0.2\sqrt{x^2 + y^2}} + 5e^{cos(3x) + sin(3y)}$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_3.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_4.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_5.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_6.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_7.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_8.png){:class="fcnplot"}

{%if page.nocontour == 'A' or page.nocontour == 'One' or page.nocontour == 'one'%}
A contour of the function is presented below:
{%else%}
{{page.nocontour}} contours of the function are presented below:
{% endif %}
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-32, 32]$ for $i=1, 2$.

# Global Minima
The function has two global minima at $f(\textbf{x}^{\ast})\approx -195.629028238419$ located at $\mathbf{x^\ast}=(\pm0.682584587365898, -0.36075325513719)$.

**Note:** Minima values are obtained with Genetic Algorithm and may not be accurate. 

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
f(x, y) = -200e^{-0.2\sqrt{x^2 + y^2}} + 5e^{cos(3x) + sin(3y)}
{% endhighlight %}

# Acknowledgement 
[Yann Chern Jou](https://github.com/danney9512) kindly helped with the correctness of this document and helped discover a bug in the code.

# See Also:
* [Ackley Function]({{site.baseurl}}/doc/ackleyfcn)
* [Ackley N. 2 Function]({{site.baseurl}}/doc/ackleyn2fcn)

# References:
* Momin Jamil and Xin-She Yang, A literature survey of benchmark functions for global optimization problems, Int. Journal of Mathematical Modelling 
and Numerical Optimisation}, Vol. 4, No. 2, pp. 150--194 (2013), arXiv:1308.4008
* D. H. Ackley, “A Connectionist Machine for Genetic Hill-Climbing,” Kluwer, 1987.
* Nayak B., Dash S.K., Sahu J.B. (2019) Validation of Well-Known Population-Based Stochastic Optimization Algorithms Using Benchmark Functions. In: Bansal J., Das K., Nagar A., Deep K., Ojha A. (eds) Soft Computing for Problem Solving. Advances in Intelligent Systems and Computing, vol 816. Springer, Singapore
