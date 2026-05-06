![example workflow](https://github.com/mazhar-ansari-ardeh/BenchmarkFcns/actions/workflows/build.yaml/badge.svg)
[![Downloads](https://static.pepy.tech/badge/benchmarkfcns)](https://pepy.tech/project/benchmarkfcns)
[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.14556621.svg)](https://doi.org/10.5281/zenodo.14556621)


# BenchmarkFcns
Benchmarkfcns is an effort to provide a high-performant, public and free implementation of well-known benchmark functions for mathematical optimization algorithms in Python. The Python library is implemented in C++ and utilizes powerful **SIMD vector calculations combined with multi-core parallel processing (via OpenMP)** to offer extremely fast and efficient evaluation of functions on massive datasets.

For the documentation of the implemented functions and their features, please visit [https://benchmarkfcns.info](https://benchmarkfcns.info).

# Key Features
- **High Performance**: Optimized C++ core using Eigen and OpenMP.
- **Parallel Execution**: Automatic multi-core processing for large batches of data.
- **SIMD Optimized**: Leverages modern CPU instruction sets for fast vector math.
- **Comprehensive Library**: Includes 100+ single-objective, multi-fidelity, and multi-objective functions.
- **Composition Engine**: Create hybrid benchmark landscapes with shifting, rotation, and scaling.

# How to use
## Python
### Installation
The library is packaged and available on the PyPI index. To install, simply run `pip install benchmarkfcns`.

### Parallel Execution
By default, the library uses all available CPU cores to evaluate large matrices of data points. You can control the number of threads used by setting the `OMP_NUM_THREADS` environment variable:

```bash
# Limit to 4 threads
export OMP_NUM_THREADS=4
python your_script.py
```

For large-scale tasks (e.g., evaluating 10 million points), this parallel implementation can provide up to **10x-30x speedup** compared to single-threaded or pure NumPy implementations.

### Usage
After installing, using the library is straightforward and all that is needed is to import the needed functions, construct a matrix of input values and call the function.
It should be noted that all the functions in the library only accept matrices as input. The rows of the matrix represent the data points at which the function should be evaluated and the columns represent the dimensions of data points. The code snippet shows how to use the library.

```python
# Import the needed function.
from benchmarkfcns import rastrigin
import numpy as np

# Look at the function's documentation.
print(rastrigin.__doc__)

# The input matrix can be list of lists.
data = [[0, 0, 0]]

# Evaluate the Rastrigin function at (0, 0, 0).
results = rastrigin(data)
print(results)

# The input can also be a Numpy matrix.
data = np.array([[0, 0, 0], [1, 1, 1]])
results = rastrigin(data)
print(results)
```

### Plotting the functions
This library is implemented to be as compatible as possible with all the mainstream plotting libraries. As a result, you are free to select your favourite plotting library to plot the functions in this library.

Plotting a mathematical function like `rastrigin` requires evaluating the function at a rather large set of data points. This is where the vectorized implementation of the functions in this package can shine as it allows performing the evaluations in a single function call, which significantly speeds up the plotting and reduces the computation cost. To facilitate this, the library also contains a helper function, `meshgrid`, for drawing 3D plots using the vectorized implemetations of the mathematical functions in this library. Given a list of *x* and *y* coordinates and a function, this function creates a meshgrid of points, evaluates the function over the meshgrid and returns the corresponding *x*, *y* and *z* points of the meshgrid that can be plotted with any plotting library.

```python
from benchmarkfcns import ackley
from benchmarkfcns.plotting import meshgrid

# Using the matplotlib library for this example
import matplotlib.pyplot as plt
import numpy as np

# Used to make title equation look nicer
import matplotlib
matplotlib.rcParams['mathtext.fontset'] = 'cm'
matplotlib.rcParams['font.family'] = 'STIXGeneral'

# We want to plot the function for x and y in range [-5, 5].
# This corresponds to a grid of 100,000,000 points.
x = np.linspace(-5, 5, 10000)
y = np.linspace(-5, 5, 10000)

# `meshgrid` creates the 3D meshgrid and evaluates `ackley` on it.
# Evaluation of 100,000,000 points took less than 3 seconds.
X, Y, Z = meshgrid(x, y, ackley)

# Create the plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plot the surface and its contour with a colormap
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.7)
ax.contour(X, Y, Z, zdir='z', offset=0, cmap='coolwarm')

# Set labels and title
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')
plt.suptitle(r"$f({\bf \vec{x}}) = -a\cdot exp\left[-b\,\sqrt{\dfrac{1}{n}\sum_{i=1}^{n}x_{i}^{2}}\right]-exp\left[\dfrac{1}{n}\sum_{i=1}^{n}cos(c\cdot x_{i})\right]+ a + exp(1)$")

# Set view angle and display
ax.view_init(14, 120)
plt.show()
```

<p align="center">
    <img src="https://raw.githubusercontent.com/mazhar-ansari-ardeh/BenchmarkFcns/master/assets/ackley.png" alt="drawing" width="700"/>
</p>

### Plotting Multi-fidelity Functions ###

Addition of multi-fidelity functions such as the `forrester` function, shown below.

```py
import benchmarkfcns.multifidelity as mfb

# Using the matplotlib library for this example
import matplotlib.pyplot as plt
import numpy as np

# Used to make title equation look nicer
import matplotlib
matplotlib.rcParams['mathtext.fontset'] = 'cm'
matplotlib.rcParams['font.family'] = 'STIXGeneral'

# We want to plot the function for x in range [0, 1].
x = np.linspace(0, 1, 10000)

# Evaluation of points took less than 340 \mu\,s, per function.
f = mfb.forrester(x)

# Create the plot
fig = plt.figure(figsize=(8,8))
ax = fig.add_subplot(111)

# Plot all 4 fidelity levels.
ax.plot(x, f[:, 0], 'k-', label=r"$f_{1}$")
ax.plot(x, f[:, 1], 'r--', label=r"$f_{2}$")
ax.plot(x, f[:, 2], 'b-.', label=r"$f_{3}$")
ax.plot(x, f[:, 3], 'g:', label=r"$f_{4}$")

# Add labels, limits, and legend.
ax.set_xlabel(r"$x$")
ax.set_ylabel(r"$f(x)$")
ax.set_xlim(0,1)
ax.set_ylim(-10.5,17)

plt.suptitle(
    r"$f_{1}(x) =~~~(6x - 2)^{2} \cdot sin(12x - 4)$"
    + f"\n"
    + r"$~~f_{2}(x) = (5.5x - 2.5)^{2} \cdot sin(12x - 4)$"
    + f"\n"
    + r"$~~f_{3}(x) = 0.75 \cdot f_{1}(x) + 5(x - 0.5) - 2$"
    + f"\n"
    + r"$~~f_{4}(x) = 0.5 \cdot f_{1}(x) + 10(x - 0.5) - 5$"
    )

plt.legend()
plt.tight_layout()
plt.show()
```

<p align="center">
    <img src="https://raw.githubusercontent.com/mazhar-ansari-ardeh/BenchmarkFcns/master/assets/forrester-mf.png" alt="drawing" width="700"/>
</p>

### Advanced Composition Engine ###

BenchmarkFcns includes a powerful **Composition Engine** that allows you to create complex, hybrid benchmark landscapes (similar to those found in the CEC competition suites) by blending multiple base functions.

The engine supports:
- **Shifting:** Move the local optimum of any component to a specific point.
- **Rotation:** Apply coordinate rotation matrices to create non-separable challenges.
- **Scaling:** Stretch or shrink individual component landscapes.
- **Exponential Blending:** Automatically blends functions based on their distance from their centers using CEC-standard weighting.

#### Example: Custom Composition
```python
import benchmarkfcns as bf
import numpy as np

# Create a new composition
comp = bf.Composition()

# Add a rotated and shifted Ackley component
n = 10
shift = np.random.uniform(-5, 5, n)
rotation = np.eye(n) # You can provide any orthogonal matrix here
comp.add("ackley", shift=shift, rotation=rotation, sigma=1.0, bias=0.0)

# Add a shifted Rastrigin component with a bias
shift2 = np.random.uniform(-5, 5, n)
comp.add("rastrigin", shift=shift2, sigma=1.0, bias=100.0)

# Evaluate a batch of points
X = np.random.uniform(-5, 5, (100, n))
scores = comp(X)
```

#### Example: CEC 2005 Presets
The library provides pre-configured factories for standard competition functions.
```python
import benchmarkfcns as bf

# Create the standard CEC 2005 F15 Hybrid Composition Function
f15 = bf.cec2005_f15(dimensions=10)

X = np.random.uniform(-5, 5, (50, 10))
results = f15(X)
```

## MATLAB
As a reference, the repository also contains the implementation of the functions in MATLAB. To install and use the MATLAB implementation, it is just required to add the project folders to MATLAB's path. For example, to use the functions in the 'benchmarks/MATLAB' folder, just navigate to this folder with MATLAB's directory explorer or use the command `addpath` with path to the folder on your PC (e.g. `addpath /path/to/benchmarks`).

# Local development and compilation
The library is built with the [pybind11](https://pybind11.readthedocs.io/), [scikit-build-core](scikit-build-core) and [Eigen](https://eigen.tuxfamily.org/) libraries. To compile the library, you will need to have CMake version 3.15 or above installed and configured. The easiest way to compile and install the package locally is to clone the repository into a directory, e.g. `BenchmarkFcns`, with submodules initialized using `git submodule update --init --recursive`, and then run `pip install ./BenchmarkFcns`. Although optional, it is highly recommended to install the package into a virtual environment.

# Contribution
Any suggestions and contributions are welcomed. The best way to contribute to the library is to fork the repository, apply the contributions and create a pull request.

# Support
Any bug reports, code contributions, suggestions, feedback and insights are greatly appreciated. If you are using this library in a research publication, please kindly consider citing the repository using the following:

*   **For the general reference of the repository:**
    ```
    Mazhar Ansari Ardeh and cmutnik. (2025). Benchmarkfcns. Zenodo. https://doi.org/10.5281/zenodo.14556621
    ```

*   **For the latest version of the repository (v3.7.0):**
    ```
    Mazhar Ansari Ardeh and cmutnik. (2026). Benchmarkfcns (version v3.7.0). Zenodo. https://doi.org/10.5281/zenodo.18912792

    ```
