BenchmarkFcns
=========================================

.. image:: https://github.com/mazhar-ansari-ardeh/BenchmarkFcns/actions/workflows/build.yaml/badge.svg
   :target: https://github.com/mazhar-ansari-ardeh/BenchmarkFcns/actions/workflows/build.yaml

**BenchmarkFcns** is a high-performance library providing a comprehensive suite of over 310 mathematical benchmark functions designed for the rigorous testing and evaluation of optimization algorithms.

By combining a core engine implemented in **C++ with Eigen** and multi-core parallelization via **OpenMP**, the library offers extremely fast evaluation speeds, often providing **10x-30x speedups** over traditional pure-Python implementations. This makes it an ideal choice for large-scale tasks, Reinforcement Learning training, and high-fidelity surrogate modeling.

Core Benefits
-------------

* **High Performance**: Optimized C++ core leveraging modern SIMD instruction sets.
* **AI & RL Ready**: Standardized **Gymnasium** (OpenAI Gym) environments for training agents on complex landscapes.
* **Massive Batch Support**: Native vectorization allows evaluating millions of data points in parallel.
* **Comprehensive Coverage**: Includes Classic (100+), Multi-Objective (50), Multi-Fidelity (49), and official CEC Competition suites (2005-2022).
* **Cross-Language Consistency**: Mathematically verified implementations ensuring consistent results across Python, C++, and MATLAB.
.. toctree::
   :maxdepth: 2
   :caption: Contents:

   usage
   api
   examples
   roadmap
   about

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
