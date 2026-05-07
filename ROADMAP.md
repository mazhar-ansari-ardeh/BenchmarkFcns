# Project Roadmap

This roadmap outlines the strategic direction for the **Benchmark Functions** library, focusing on performance, scalability, and comprehensiveness.

## Phase 1: High-Performance Core (Completed)
- [x] Implement `apply_parallel` utility for multi-core execution.
- [x] Refactor all single-objective functions to use parallel backends.
- [x] Parallelize multi-fidelity and multi-objective libraries.
- [x] Integrate `clang-format` for automated C++ code quality.
- [x] Verify speedups (up to 32x) compared to NumPy/Serial implementations.

## Phase 2: Optimization & Integration (In Progress)
- [ ] **Vectorize Optimizers**: Refactor the Artificial Bee Colony (ABC) optimizer to use matrix-based evaluations, leveraging the parallel C++ backend.
- [ ] **Composition Engine Optimization**: Parallelize the outer evaluation loop of the hybrid composition engine.
- [ ] **Standardized Test Suite**: Implement a comprehensive `pytest` and `GoogleTest` suite to ensure mathematical correctness across all platforms.
- [ ] **CI/CD Enhancement**: Add automated testing to the wheel-building pipeline.

## Phase 3: Library Expansion
- [ ] **Implement Classic Functions**: Add the 100 missing classic single-objective functions identified in [RECOMMENDED_FUNCTIONS.md](RECOMMENDED_FUNCTIONS.md). (15/100 completed)
- [ ] **Expand Multi-Objective Support**: Implement the WFG suite and CEC 2009 UF/CF sets.
- [ ] **Build Multi-Fidelity Library**: Implement physical surrogates and bi-fidelity adaptations for all major benchmarks.

## Phase 4: Long-Term Goals
- [ ] **CEC Competition Suites**: Integrate full support for CEC 2014, 2017, 2019, and 2022 suites.
- [ ] **Automated Documentation**: Generate searchable API and mathematical documentation using Sphinx/Doxygen.
- [ ] **Benchmarking Dashboard**: Create an automated system to track performance regressions across different CPU architectures.
