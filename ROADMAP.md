# Project Roadmap

This roadmap outlines the strategic direction for the **Benchmark Functions** library, focusing on performance, scalability, and comprehensiveness.

## Phase 1: High-Performance Core (Completed)
- [x] Implement `apply_parallel` utility for multi-core execution.
- [x] Refactor all single-objective functions to use parallel backends.
- [x] Parallelize multi-fidelity and multi-objective libraries.
- [x] Integrate `clang-format` for automated C++ code quality.
- [x] Verify speedups (up to 32x) compared to NumPy/Serial implementations.

## Phase 2: Optimization & Integration (Completed)
- [x] **Integration Examples**: Provide high-quality examples for integrating `BenchmarkFcns` with established libraries like `SciPy`, `PyGMO`, and `Nevergrad`.
- [x] **Composition Engine Optimization**: Parallelize the outer evaluation loop of the hybrid composition engine.
- [ ] **Standardized Test Suite**: Implement a comprehensive `pytest` and `GoogleTest` suite to ensure mathematical correctness across all platforms. (In Progress)
- [ ] **CI/CD Enhancement**: Add automated testing to the wheel-building pipeline.

## Phase 3: Library Expansion (Completed)
- [x] **Implement Classic Functions**: Add the 100 missing classic single-objective functions identified in [RECOMMENDED_FUNCTIONS.md](RECOMMENDED_FUNCTIONS.md).
- [x] **Expand Multi-Objective Support**: Implement the WFG suite, CEC 2009 UF/CF sets, and Many-Objective (MaF) suite.
- [x] **Build Multi-Fidelity Library**: Implement physical surrogates and bi-fidelity adaptations for all major benchmarks.

## Phase 4: Long-Term Goals (Completed)
- [x] **CEC Competition Suites**: Integrated full support for CEC 2005, 2014, 2017, 2019, 2020, and 2022 suites with embedded data.
- [x] **Automated Documentation**: Generate searchable API and mathematical documentation using Sphinx/Doxygen.

## Phase 5: AI & Reinforcement Learning Integration (Completed)
- [x] **Gymnasium Environment Wrappers**: Standardized `gym.Env` wrappers for all major benchmark functions to support RL training.
- [x] **Baseline AI Agents**: Provided example training scripts using popular libraries like `Stable Baselines3`.

## Phase 6: Optimization Intelligence (Upcoming)
- [ ] **Automatic Differentiation**: Integrate C++ autodiff to provide exact gradients and Hessians for all 310+ functions.
- [ ] **Exploratory Landscape Analysis (ELA)**: Implement modules to calculate ruggedness, separability, and basin size to help users classify their own problems.
- [ ] **Stochastic & Constrained Suites**: Add official support for noisy fitness landscapes and complex constraint handling (CEC standard).

## Phase 7: Massive Scale & Portability (Upcoming)
- [ ] **GPU Acceleration**: Implement a CUDA/SYCL backend for the evaluation engine to support billion-scale batch evaluations.
- [ ] **Rust & Julia Bindings**: Leverage the C++ core to provide high-performance native libraries for the Rust and Julia ecosystems.

## Continuous Quality & Expansion (Ongoing)
- [ ] **100% Mathematical Coverage**: Expand the `pytest` suite to verify every single function in the library against ground-truth optima.
- [ ] **Library Growth**: Continue adding modern benchmarks from the latest optimization literature (Physical Surrogates, Quantum-inspired landscapes).
