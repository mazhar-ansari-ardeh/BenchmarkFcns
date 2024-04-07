% Draws mesh of a functionon the 3-dimensional space
%
% meshfcn(FCN, X, Y) draws the mesh of the function given by the
% handle FCN in the x-y plane defined over the intervals specified by X
% and Y
%
% meshfcn(FCN, X, Y, X_LABEL) draws the mesh and uses X_LABEL as the
% label of x-axis
%
% meshfcn(FCN, X, Y, X_LABEL, Y_LABEL) draws the mesh and uses
% X_LABEL as the label of x-axis and Y_LABEL as the label of the y-axis
%
% meshfcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL) draws the mesh and
% uses X_LABEL as the label of x-axis, Y_LABEL as the label of the y-axis
% and Z_LABEL as the label of the z-axis
%
% meshfcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL, PLT_TITLE) draws the
% mesh and uses PLT_TITLE as the title of the plot.
%
% meshfcn(FCN, X, Y, X_LABEL, Y_LABEL, Z_LABEL, PLT_TITLE, USE_COLORBAR)
% if USE_COLORBAR is true, a color bar will also be drawn.
%
% [H] = meshfcn(...) returns a handle, H, to a  surface plot object.
% AXIS, CAXIS, COLORMAP, HOLD, SHADING, HIDDEN and VIEW set figure,
% axes, and surface properties which affect the display of the mesh.
%
% See also: contourfcn, surffcn
%
% Example:
%   x = -10:0.01:10;
%   y = x;
%   meshfcn(@ackleyfcn, x, y, 'x_1', 'x_2', 'z', true)
%
% Author: Mazhar Ansari Ardeh
% Please forward any comments or bug reports to mazhar.ansari.ardeh at
% Google's e-mail service or feel free to kindly modify the repository.
function h = meshfcn(fcn, x, y, x_label, y_label, z_label, plt_title, use_colorbar)
    [X, Y] = meshgrid(x, y);
    Z = arrayfun(@(xx, yy)(fcn([xx, yy])), X, Y);
    [h] = mesh(X, Y, Z);

    if nargin >= 4
        xlabel(x_label)
    end

    if nargin >= 5
        ylabel(y_label)
    end

    if nargin >= 6
        zlabel(z_label)
    end

    if nargin >= 7
        title(plt_title)
    end

    if nargin >= 8 && use_colorbar
        colorbar
    end
end
