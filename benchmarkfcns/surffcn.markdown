---
layout: page
plotting: true
title: Surf Function
categories: optimization, benchmark, plotting
tags: plotting
fname: surffcnfcn
functionname: SurfFunction
---
Draws surf of a functionon the 3-dimensional space.
 
`surffcn(FCN, X, Y)` draws the surf of the function given by the 
handle `FCN` in the x-y plane defined over the intervals specified by X 
and Y
 
`surffcn(FCN, X, Y, X_LABEL)` draws the surf and uses `X_LABEL` as the 
label of x-axis.

`surffcn(FCN, X, Y, X_LABEL, Y_LABEL)` draws the surf and uses 
`X_LABEL` as the label of x-axis and `Y_LABEL` as the label of the y-axis.

`surffcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL)` draws the surf and 
uses `X_LABEL` as the label of x-axis, `Y_LABEL` as the label of the y-axis 
and `Z_LABEL` as the label of the z-axis.

`surffcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL, PLT_TITLE)` draws the
surf and uses `PLT_TITLE` as the title of the plot. 

`surffcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL, PLT_TITLE, USE_COLORBAR)`
if `USE_COLORBAR` is true, a color bar will also be drawn. 

`[H] = surffcn(...)` returns a handle, H, to a  surface plot object. 
`AXIS`, `CAXIS`, `COLORMAP`, `HOLD`, `SHADING`, `HIDDEN` and `VIEW` set figure,
axes, and surface properties which affect the display of the surf.

# Example
{%highlight MATLAB%}   
   x = -10:0.01:10;
   y = x; 
   surffcn(@ackleyfcn, x, y, 'x_1', 'x_2', 'z', true)
{% endhighlight %}

# See also 
* [MeshFcn]({{site.baseurl}}/benchmarkfcns/meshfcn)
* [ContourFcn]({{site.baseurl}}/benchmarkfcns/contourfcn)
