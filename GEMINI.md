# GEMINI.md - Project Context: BenchmarkFcns

This document provides foundational context, architectural overview, and development guidelines for the **BenchmarkFcns** project.

## Project Overview
**BenchmarkFcns** is a high-performance library providing a comprehensive suite of mathematical benchmark functions for testing and validating optimization algorithms.

### Key Purpose
- Provide mathematically accurate and consistent implementations of standard test functions (e.g., Ackley, Rastrigin, Rosenbrock).
- Support multiple environments: **Python** (primary), **MATLAB**, and **C++**.
- Provide high-quality **LaTeX** documentation for each function.

### Core Technologies
- **C++17**: High-performance core using **Eigen 3.4.0** for linear algebra.
- **OpenMP**: Multi-core parallelization for large-scale batch evaluations.
- **SIMD**: Leverages Eigen's expression templates for optimal vectorization.
- **Python**: Bound via **pybind11** and built with **scikit-build-core**.
- **Poetry**: Dependency and environment management for the Python package.
- **MATLAB**: Pure `.m` file implementations for research consistency.

## Architecture
The project is structured to prioritize performance while maintaining cross-language compatibility:

- `src/C++`: The high-performance engine.
    - `benchmarkfcns.cpp`: Implementations of 100+ single-objective functions.
    - `multifidelity.cpp`: Multi-fidelity variants with varying accuracy levels.
    - `multiobjective.cpp`: Problems with multiple conflicting objectives.
    - `composition.cpp`: Engine for creating hybrid landscapes (CEC standard).
    - `utils.h`: Contains the `apply_parallel` utility for unified threading/SIMD logic.
- `src/python/benchmarkfcns`: Python wrappers and the advanced `Composition` class.
- `src/matlab`: MATLAB-native implementations.
- `src/latex`: TeX definitions and mathematical properties for documentation.
- `optimiser`: Implementations of optimizers like Artificial Bee Colony (ABC).

## Building and Running

### Python Environment
The project uses Poetry. To set up the environment:
```bash
poetry install
```

### Local Development Build
To compile the C++ core and install the package in editable mode:
```bash
poetry run pip install -e .
```

### Controlling Parallelism
The C++ core uses OpenMP. You can control the number of threads via environment variables:
```bash
export OMP_NUM_THREADS=4  # Limit to 4 cores
```

### Benchmarking
Several scripts are available in the root for performance verification:
- `benchmark_rastrigin.py`: Basic C++ vs SIMD/Parallel verification.
- `compare_cpp_vs_numpy.py`: Performance comparison against pure NumPy.

## Development Conventions

### Parallelization Pattern
All new functions should be implemented using the `apply_parallel` utility in `utils.h`. This ensures that they automatically support both SIMD (via Eigen Array) and multi-core execution.

Example:
```cpp
return apply_parallel(x, [](const auto& a) {
    // 'a' is an Eigen::ArrayWrapper
    return VectorXd(a.square().rowwise().sum());
});
```

### Coding Style & Linting
- **C++**: Adheres to the `.clang-format` (LLVM-based with 4-space indent).
- **Python**: Managed by `ruff`.
- **Pre-commit**: Always ensure `pre-commit run --all-files` passes before committing.

### Organization
- Functions in `benchmarkfcns.cpp` should be maintained in **alphabetical order**.
- New functions must be registered in the `get_function_ptr` map within `composition.cpp` to be available to the Hybrid Composition engine.

## Roadmap & Future Work
Refer to `ROADMAP.md` for the strategic plan and `RECOMMENDED_FUNCTIONS.md` for a curated list of missing classic, multi-objective, and multi-fidelity functions.

## General guidelines
- Do not ask questions like "is there anything else you would like to do" or similar ones. Instead, and only if you have any recommendations, just give the recommendation.
