from functools import partial
from benchmarkfcns import biggsexp02
from benchmarkfcns.plotting import meshgrid

# Using the matplotlib library for this example
import matplotlib.pyplot as plt
import numpy as np

# Used to make title equation look nicer
import matplotlib

matplotlib.rcParams["mathtext.fontset"] = "cm"
matplotlib.rcParams["font.family"] = "STIXGeneral"

# We want to plot the function for x and y in range [-5, 5].
# This corresponds to a grid of 100,000,000 points.
x = np.linspace(0, 20, 1000)
y = np.linspace(0, 20, 1000)

# print(sphere(np.array([[-0.1, 0.1], [ -0.2, 0.2]])))

# `meshgrid` creates the 3D meshgrid and evaluates `biggsexp02` on it.
# # Evaluation of 100,000,000 points took less than 3 seconds.
fcn = partial(biggsexp02)
X, Y, Z = meshgrid(x, y, fcn)

# Create the plot
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Plot the surface and its contour with a colormap
ax.plot_surface(X, Y, Z, cmap="viridis", alpha=0.7)
ax.contour(X, Y, Z, zdir="z", offset=0, cmap="coolwarm")

# Set labels and title
ax.set_xlabel("X-axis")
ax.set_ylabel("Y-axis")
ax.set_zlabel("Z-axis")
plt.suptitle(
    r"$f({\bf \vec{x}}) = \sum_{i=1}^{10} \left( e^{-t_i x_1} - 5e^{-t_i x_2} - y_i \right)^2$"
)

# Set view angle and display
ax.view_init(14, 120)
plt.show()
