---
layout: page
plotting: true
title: Contour Function
categories: optimization, benchmark, plotting
tags: plotting 
fname: contourfcn
functionname: ContourFcn
---
Draws contour of a functionon the 3-dimensional space

`contourfcn(FCN, X, Y)` draws the contour of the function given by the 
handle `FCN` in the x-y plane defined over the intervals specified by X 
and Y.

`contourfcn(FCN, X, Y, X_LABEL)` draws the contour and uses `X_LABEL` as the 
label of x-axis.

`contourfcn(FCN, X, Y, X_LABEL, Y_LABEL)` draws the contour and uses 
`X_LABEL` as the label of x-axis and `Y_LABEL` as the label of the y-axis.

`contourfcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL)` draws the contour and 
uses `X_LABEL` as the label of x-axis, `Y_LABEL` as the label of the y-axis 
and `Z_LABEL` as the label of the z-axis.

`contourfcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL, PLT_TITLE)` draws the contour and uses `PLT_TITLE` as the title of the plot. 

`contourfcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL, PLT_TITLE, USE_COLORBAR)`
if `USE_COLORBAR` is true, a color bar will also be drawn. 

`[C, H] = contourfcn(...)` returns contour matrix `C` and a handle, `H`, to
a contour object. These can be used as inputs to `CLABEL`. The structure of 
a contour matrix is described in MATLAB's help for `CONTOURC`.

# Example: 
{%highlight MATLAB%}   
  x = -10:0.01:10;
  y = x; 
  contourfcn(@ackleyfcn, x, y, 'x_1', 'x_2', 'z', true)
{% endhighlight %}

# See also 
* [Mesh Function]({{site.baseurl}}/benchmarkfcns/meshfcn)
* [Surf Function]({{site.baseurl}}/benchmarkfcns/surffcn)
