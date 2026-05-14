import numpy as np
import benchmarkfcns as bf
import time


def run_benchmark(n_points, dimensions):
    print(f"Benchmarking Rastrigin with {n_points:,} points in {dimensions}D...")

    # Generate random data
    x = np.random.uniform(-5.12, 5.12, (n_points, dimensions)).astype(np.float64)

    # 1. Standard Vectorized (SIMD only)
    start = time.perf_counter()
    res_simd = bf.rastrigin(x)
    end = time.perf_counter()
    simd_time = end - start
    print(f"Standard (SIMD): {simd_time:.4f} seconds")

    # 2. Parallel Vectorized (SIMD + Multi-core)
    start = time.perf_counter()
    res_parallel = bf.rastrigin_parallel(x)
    end = time.perf_counter()
    parallel_time = end - start
    print(f"Parallel (SIMD+OMP): {parallel_time:.4f} seconds")

    # Verify results (using a subset to save time if needed, but 10M is fine)
    if np.allclose(res_simd, res_parallel):
        print("Verification: SUCCESS (Results match)")
    else:
        print("Verification: FAILURE (Results differ)")

    speedup = simd_time / parallel_time
    print(f"Speedup: {speedup:.2f}x")


if __name__ == "__main__":
    # Test with a very large matrix (10 million points)
    run_benchmark(10_000_000, 30)
