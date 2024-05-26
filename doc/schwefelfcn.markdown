---
layout: page
resource: true
title: Schwefel Function
categories: optimization, benchmark
tags: continuous multimodal non-convex non-differentiable non-separable
fname: schwefelfcn
sname: schwefel
functionname: Schwefel Function
excerpt: The Schwefel function is a multimodal, n-dimensional non-convex mathematical function widely used for testing optimization algorithms
---

# Mathematical Definition

{%raw%}

$$f(\textbf{x}) = f(x_1, x_2, ..., x_n) = 418.9829d -{\sum_{i=1}^{n} x_i sin(\sqrt{|x_i|})}.$$

{%endraw%}

# Plots
![{{page.functionname}}]({{site.baseurl}}/doc/plots/{{page.fname}}.png){:class="fcnplot"}

The contour of the function: 
![{{page.functionname}} Contour]({{site.baseurl}}/doc/plots/{{page.fname}}_contour.png){:class="fcnplot"}

# Description and Features
* The function is continuous.
* The function is not [convex](https://en.wikipedia.org/wiki/Convex_function).
* The function can be defined on n-dimensional space. 
* The function is multimodal.
* The function is not {{page.separable}}.

# Input Domain
The function can be defined on any input domain but it is usually evaluated on the hypercube $x_i \in [-500, 500]$ for $i = 1..n$.

# Global Minima
$f(\textbf{x}^{\ast}) = 0$ at $\textbf{x}^{\ast} = (420.9687, ..., 420.9687)$

# Implementation
#### Python
For Python, the function is implemented in the [benchmarkfcns package](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns), which can be installed from command line with `pip install benchmarkfcns`. 

{%highlight Python%}
from benchmarkfcns import {{page.sname}}

print({{page.sname}}([[0, 0, 0],
              [1, 1, 1]]))
{% endhighlight %}

#### MATLAB
An implementation of the **{{page.functionname}}** with MATLAB is provided below. **{{page.functionname}}** can be implemented with a `for` loop that iterates over all the components of the input vector but, MATLAB and Octave have built-in facilities that makes the implementation more efficient and concise.

{%highlight MATLAB%}
% Computes the value of the Schwefel benchmark function.
% SCORES = SCHWEFELFCN(X) computes the value of the Schwefel function at 
% point X. SCHWEFELFCN accepts a matrix of size M-by-2 and returns a  
% vetor SCORES of size M-by-1 in which each row contains the function value 
% for the corresponding row of X.
% For more information please visit: 
% 
% Author: Mazhar Ansari Ardeh
function scores = schwefelfcn(x)
    n = size(x, 2);
    scores = 418.9829 * n - (sum(x .* sin(sqrt(abs(x))), 2));
end
{% endhighlight %}

The function can be represented in Latex as follows:
{% highlight latex%}
f(\textbf{x}) = f(x_1, x_2, ..., x_n) = 418.9829d -{\sum_{i=1}^{n} x_i sin(\sqrt{|x_i|})}
{% endhighlight %}

# References:
* http://www.sfu.ca/~ssurjano
