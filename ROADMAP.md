# Project Roadmap

This roadmap outlines the strategic direction for the **Benchmark Functions** library, focusing on performance, scalability, and comprehensiveness.

## Phase 1: High-Performance Core (Completed)
- [x] Implement `apply_parallel` utility for multi-core execution.
- [x] Refactor all single-objective functions to use parallel backends.
- [x] Parallelize multi-fidelity and multi-objective libraries.
- [x] Integrate `clang-format` for automated C++ code quality.
- [x] Verify speedups (up to 32x) compared to NumPy/Serial implementations.

## Phase 2: Optimization & Integration (Completed)
- [ ] **Integration Examples**: Provide high-quality examples for integrating `BenchmarkFcns` with established libraries like `SciPy`, `PyGMO`, and `Nevergrad`.
- [x] **Composition Engine Optimization**: Parallelize the outer evaluation loop of the hybrid composition engine.
- [ ] **Standardized Test Suite**: Implement a comprehensive `pytest` and `GoogleTest` suite to ensure mathematical correctness across all platforms.
- [ ] **CI/CD Enhancement**: Add automated testing to the wheel-building pipeline.

## Phase 3: Library Expansion (Completed)
- [x] **Implement Classic Functions**: Add the 100 missing classic single-objective functions identified in [RECOMMENDED_FUNCTIONS.md](RECOMMENDED_FUNCTIONS.md).
- [x] **Expand Multi-Objective Support**: Implement the WFG suite, CEC 2009 UF/CF sets, and Many-Objective (MaF) suite.
- [x] **Build Multi-Fidelity Library**: Implement physical surrogates and bi-fidelity adaptations for all major benchmarks.

## Phase 4: Long-Term Goals (Completed)
- [x] **CEC Competition Suites**: Integrated full support for CEC 2005, 2014, 2017, 2019, 2020, and 2022 suites with embedded data.
- [x] **Automated Documentation**: Generate searchable API and mathematical documentation using Sphinx/Doxygen.
- [ ] **Benchmarking Dashboard**: Create an automated system to track performance regressions.

## Phase 5: AI & Reinforcement Learning Integration (Planned)
- [ ] **Gymnasium Environment Wrappers**: Implement standardized `gym.Env` wrappers for all major benchmark functions to support RL training.
- [ ] **Optimization-as-a-Service**: Develop a lightweight Python API for using benchmark functions as black-box training environments.
- [ ] **Baseline AI Agents**: Provide example training scripts using popular libraries like `Stable Baselines3` or `CleanRL`.
- [ ] **Hyperparameter Benchmarking**: Create a suite for testing the sensitivity of AI optimizers to function landscapes (noise, ruggedness, etc.).
