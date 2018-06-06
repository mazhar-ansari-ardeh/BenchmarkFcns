---
layout: page
resource: true
title: Ackley Function
categories: optimization, benchmark
tags: n-dimensional continuous multimodal non-convex differentiable
fname: ackleyfcn
functionname: Ackley Function
modal: multimodal
dimension: n-dimensional
---
<head>
	<script type="text/x-mathjax-config">
	  MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});
	</script>
	<script type="text/javascript" async
	  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_CHTML">
	</script>
	
	<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
    <script>
        (adsbygoogle = window.adsbygoogle || []).push({
            google_ad_client: "ca-pub-9102949842529833",
            enable_page_level_ads: true
        });
    </script>
</head>


# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, ..., x_n)= -a.exp(-b\sqrt{\frac{1}{n}\sum_{i=1}^{n}x_i^2})-exp(\frac{1}{d}\sum_{i=1}^{n}cos(cx_i))+ a + exp(1)$$

{%endraw%}
In the above equation, the values $a$, $b$ and $c$ are constants and are usually chosen as $a=20$, $b=0.2$ and $c=2\pi$.

# Plots
![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}.png){:class="fcnplot"}

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_2.png){:class="fcnplot"}

The contour of the function is as presented below:

![{{page.functionname}}]({{site.baseurl}}/benchmarkfcns/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function is defined on {{page.dimension}} space. 
* The function is {{page.modal}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on $x_i \in [-32, 32]$ for all $i = 1,...,n$.

# Global Minima
The function has one global minimum at: $f(\textbf{x}^{\ast})=0$ at $\textbf{x}^{\ast} = (0, ..., 0)$.

# Implementation
An implementation of the **{{page.functionname}}** with MATLAB is provided below. 

{%highlight MATLAB%}
{% include {{page.fname}}.m %}
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = f(x_1, ..., x_n)= -a.exp(-b\sqrt{\frac{1}{n}\sum_{i=1}^{n}x_i^2})-exp(\frac{1}{d}\sum_{i=1}^{n}cos(cx_i))+ a + exp(1)
{% endhighlight %}

# References:
* [http://www.sfu.ca/~ssurjano/ackley.html](http://www.sfu.ca/~ssurjano/ackley.html)
* [https://en.wikipedia.org/wiki/Test_functions_for_optimization](https://en.wikipedia.org/wiki/Test_functions_for_optimization)
* [http://www.cs.unm.edu/~neal.holts/dga/benchmarkFunction/ackley.html](http://www.cs.unm.edu/~neal.holts/dga/benchmarkFunction/ackley.html), This resource 
contains an extensive collection of references for this function. The page also contains an implementation of the function in `Python`.
