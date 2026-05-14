import time
import numpy as np
import benchmarkfcns as bf
import os


def np_sphere(x):
    return np.sum(x**2, axis=1)


def np_ackley(x):
    n = x.shape[1]
    sum1 = np.sum(x**2, axis=1)
    sum2 = np.sum(np.cos(2 * np.pi * x), axis=1)
    return (
        -20.0 * np.exp(-0.2 * np.sqrt(sum1 / n)) - np.exp(sum2 / n) + 20.0 + np.exp(1.0)
    )


def np_rastrigin(x):
    n = x.shape[1]
    return 10 * n + np.sum(x**2 - 10 * np.cos(2 * np.pi * x), axis=1)


def np_rosenbrock(x):
    return np.sum(
        100.0 * (x[:, 1:] - x[:, :-1] ** 2) ** 2 + (x[:, :-1] - 1.0) ** 2, axis=1
    )


def run_comparison(name, cpp_func, np_func, points, dims):
    x = np.random.uniform(-5, 5, (points, dims)).astype(np.float64)

    # Warmup
    _ = cpp_func(x[:100])
    _ = np_func(x[:100])

    # C++ Parallel
    os.environ["OMP_NUM_THREADS"] = str(os.cpu_count() or 4)
    start = time.perf_counter()
    res_cpp = cpp_func(x)
    t_cpp = time.perf_counter() - start

    # NumPy
    start = time.perf_counter()
    res_np = np_func(x)
    t_np = time.perf_counter() - start

    # Verification
    valid = np.allclose(res_cpp, res_np, atol=1e-8)

    return t_cpp, t_np, valid


def main():
    points = 5_000_000
    dims = 30

    print(f"Benchmarking {points:,} points in {dims}D")
    print(
        f"{'Function':<15} | {'C++ (s)':<10} | {'NumPy (s)':<10} | {'C++ Speedup':<12} | {'Valid'}"
    )
    print("-" * 65)

    benchmarks = [
        ("sphere", bf.sphere, np_sphere),
        ("ackley", bf.ackley, np_ackley),
        ("rastrigin", bf.rastrigin, np_rastrigin),
        ("rosenbrock", bf.rosenbrock, np_rosenbrock),
    ]

    for name, cpp_f, np_f in benchmarks:
        t_cpp, t_np, valid = run_comparison(name, cpp_f, np_f, points, dims)
        speedup = t_np / t_cpp
        print(
            f"{name:<15} | {t_cpp:<10.4f} | {t_np:<10.4f} | {speedup:<12.2f}x | {valid}"
        )


if __name__ == "__main__":
    main()
