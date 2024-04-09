# BenchmarkFcns
Benchmarkfcns is an effort to provide a high-perfomant, public and free implementation of well-known benchmark functions for mathematical optimization algorithms in Python and MATLAB. The Python library is implemented in C++ using the Eigen library's SIMD vector operations to provide.

# How to install
## Python
The library is packaged and available on the PyPI index. To install, simply run `pip install benchmarkfcns`.

### Local development and compilation
The library is built with with [pybind11](https://pybind11.readthedocs.io/), [scikit-build-core](scikit-build-core) and [Eigen](https://eigen.tuxfamily.org/). To compile the library, you will need to have CMake version 3.15 or above installed and configured. The easiest way to compile and install the package locally is to clone the repository, e.g. `BenchmarkFcns`, and then run `pip install ./BenchmarkFcns`. Although optional, it is highly recommended to install the package into a virtual environment.

### Contribution
Any suggestions and contributions are welcomed. The best way to contribute to the library is to fork the repository, apply the contributions and create a pull request.


## MATLAB
To install and use the MATLAB implementation, it is just required to add the project folders to MATLAB's path. For example, to use the functions in the 'benchmarks/MATLAB' folder, just navigate to this folder with MATLAB's directory explorer or use the command `addpath` with path to the folder on your PC (e.g. `addpath /path/to/benchmarks`).

# Support
Any bug reports, code contributions, suggestions, feedback and insights are greatly appreciated. If you are using this library in a research publication, please kindly consider citing the repository as "Ardeh, M. A. [2024] BenchmarkFcns [Source Code]. GitHub. https://github.com/mazhar-ansari-ardeh/BenchmarkFcns".
