---
layout: page
resource: true
title: Ridge Function
categories: optimization, benchmark
tags: n-dimensional non-separable unimodal non-convex differentiable
fname: ridgefcn
functionname: Ridge Function
modal: unimodal
dimension: n-dimensional
separable: non-separable
differentiable: differentiable
convex: is not [convex](https://en.wikipedia.org/wiki/Convex_function)
nocontour: Two
excerpt: Ridge function is a unimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = x_1 + d\left(\sum_{i=2}^{n}x_i^2\right)^\alpha$$

{%endraw%}

In this formula, $$d$$ and $$\alpha$$ are constants and are usually set to $$d = 1, \lpha=0.5$$.

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_3.png){:class="fcnplot"}


{%if page.nocontour == 'A' or page.nocontour == 'One' or page.nocontour == 'one'%}
A contour of the function is presented below:
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}
{%else%}
{{page.nocontour}} contours of the function are presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour_2.png){:class="fcnplot"}
{% endif %}

# Description and Features
* The function {{page.convex}}.
* The function is defined on {{page.dimension}} space.
* The function is {{page.separable}}.
* The function is {{page.differentiable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-20, 0]$ for $i=1, 2$.

# Global Minima
The function has one global minimum at $f(\textbf{x}^{\ast})= e^{-200}$ located at $\mathbf{x^\ast}=(-10, -10)$.

# Implementation
An implementation of the **{{page.functionname}}** with `MATLAB` is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = x_1 + d\left(\sum_{i=2}^{n}x_i^2\right)^\alpha
{% endhighlight %}


# References:
* Beyer HG., Finck S. (2012) HappyCat – A Simple Function Class Where Well-Known Direct Search Algorithms Do Fail. In: Coello C.A.C., Cutello V., Deb K., Forrest S., Nicosia G., Pavone M. (eds) Parallel Problem Solving from Nature - PPSN XII. PPSN 2012. Lecture Notes in Computer Science, vol 7491. Springer, Berlin, Heidelberg, [https://doi.org/10.1007/978-3-642-32937-1_37](https://doi.org/10.1007/978-3-642-32937-1_37)
