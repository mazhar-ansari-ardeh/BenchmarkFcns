# BenchmarkFcns: Deep Research Report

## Project Overview
BenchmarkFcns is a high-performance Python library providing a comprehensive suite of benchmark functions used to test and evaluate mathematical optimization algorithms. The core philosophy of the project is to provide extremely fast and efficient evaluations, especially when handling large batches of data points.

## Key Findings

### 1. High-Performance Core (C++ and Eigen)
The project's performance is driven by its C++ implementation.
- **Eigen Integration:** It uses the Eigen library for linear algebra. Most functions are implemented using Eigen's `array()` API, which allows for expressive, vectorized code that Eigen can further optimize using SIMD (Single Instruction, Multiple Data) instructions (SSE, AVX, etc.).
- **Vectorized Evaluation:** Unlike traditional implementations that evaluate one point at a time, this library is designed to evaluate multiple data points simultaneously. It accepts $M \times N$ matrices (M points in N dimensions) and returns a vector of $M$ scores.
- **Zero-Copy Interface:** Using `pybind11` and `Eigen::Ref`, the library minimizes data copying between Python (NumPy) and C++.

### 2. Multi-fidelity Support
A distinctive feature is the support for multi-fidelity functions, which are crucial in surrogate modeling and multi-fidelity optimization.
- **Implemented Functions:** Multi-fidelity versions of Booth, Forrester, and Rosenbrock are included.
- **Fidelity Levels:** For example, the `forrester` function provides 4 different fidelity levels, allowing researchers to simulate scenarios where low-fidelity data is cheaper to obtain than high-fidelity data.

### 3. MATLAB Reference Implementation
The project maintains a complete parallel implementation in MATLAB.
- This serves as a "ground truth" and provides a familiar environment for researchers who primarily use MATLAB.
- The MATLAB implementation also follows the vectorized input pattern ($M \times N$ matrices).

### 4. Documentation and Visualization
- **LaTeX Documentation:** Each function's mathematical definition is stored in a separate `.tex` file in `src/latex`.
- **Plotting Helpers:** The library includes a `meshgrid` utility in `src/python/benchmarkfcns/plotting.py` specifically optimized to use the vectorized nature of the functions for generating 3D surfaces rapidly.
- **Detailed Docstrings:** The C++ bindings include extensive docstrings that describe function properties like global minima, domain, and modality.

### 5. Performance Evolution (Case Study)
The root directory contains comparison scripts (`basic.py`, `basic_simd.py`, `basic_np_simd.py`) that demonstrate the performance gains:
- **Baseline:** Standard iterative evaluation.
- **SIMD (Library):** Batch evaluation using the C++ core.
- **NumPy SIMD:** Batch evaluation using NumPy's built-in vectorization.
The C++ implementation is designed to compete with or outperform NumPy by using specialized SIMD kernels and minimizing Python overhead.

## Technical Specificities

- **Build System:** Uses `scikit-build-core` and `pybind11` for a modern, reliable C++ extension build process.
- **Dimension Constraints:** Many functions are generalized to N-dimensions, while others (like `beale`, `booth`, `adjiman`) are strictly 2D as per their mathematical definitions, with explicit checks in the C++ code.
- **Parameterization:** Some functions allow optional parameters (e.g., `alpha` in `happycat`, `beta` and `m` in `xinsheyangn3`) providing flexibility for different benchmark scenarios.

## Future Directions (based on TODO.txt)
- Addition of more complex benchmark functions from sources like CEC competitions (CEC2005, etc.).
- Improved documentation and coverage for specific functions like Bukin, Chichinadze, and Treccani on GitHub Pages.
- More efficient tensor operations (currently noted as a bottleneck in some complex functions like `watson`).

---
*Report generated on March 27, 2026*
