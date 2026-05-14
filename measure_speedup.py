import os
import subprocess
import sys

# A list of functions to benchmark with their recommended dimensions
# and the number of points to test with.
BENCHMARKS = [
    {"name": "sphere", "dims": 30, "points": 10_000_000},
    {"name": "ackley", "dims": 30, "points": 5_000_000},
    {"name": "rastrigin", "dims": 30, "points": 5_000_000},
    {"name": "rosenbrock", "dims": 30, "points": 5_000_000},
    {"name": "griewank", "dims": 30, "points": 5_000_000},
    {"name": "schwefel", "dims": 30, "points": 5_000_000},
    {"name": "levy", "dims": 30, "points": 5_000_000},
    {"name": "michalewicz", "dims": 30, "points": 2_000_000},
    {"name": "weierstrass", "dims": 30, "points": 1_000_000},
    {"name": "gallagher101", "dims": 30, "points": 500_000},
]

WORKER_CODE = """
import sys
import time
import numpy as np
import benchmarkfcns as bf

name = sys.argv[1]
dims = int(sys.argv[2])
points = int(sys.argv[3])

func = getattr(bf, name)
x = np.random.uniform(-5, 5, (points, dims)).astype(np.float64)

# Warmup
_ = func(x[:100])

start = time.perf_counter()
_ = func(x)
end = time.perf_counter()

print(end - start)
"""


def run_worker(name, dims, points, threads):
    env = os.environ.copy()
    env["OMP_NUM_THREADS"] = str(threads)

    cmd = [sys.executable, "-c", WORKER_CODE, name, str(dims), str(points)]
    result = subprocess.run(cmd, env=env, capture_output=True, text=True)

    if result.returncode != 0:
        print(f"Error running {name}: {result.stderr}")
        return None

    try:
        return float(result.stdout.strip())
    except ValueError:
        print(f"Could not parse output for {name}: {result.stdout}")
        return None


def main():
    print(
        f"{'Function':<15} | {'Points':<10} | {'Serial (s)':<12} | {'Parallel (s)':<12} | {'Speedup':<8}"
    )
    print("-" * 70)

    for b in BENCHMARKS:
        name = b["name"]
        dims = b["dims"]
        points = b["points"]

        # Run Serial
        t_serial = run_worker(name, dims, points, 1)

        # Run Parallel (default threads)
        # Using a large number to let OpenMP decide or just let it use all
        t_parallel = run_worker(name, dims, points, os.cpu_count() or 4)

        if t_serial and t_parallel:
            speedup = t_serial / t_parallel
            print(
                f"{name:<15} | {points:<10,} | {t_serial:<12.4f} | {t_parallel:<12.4f} | {speedup:<8.2f}x"
            )
        else:
            print(f"{name:<15} | Failed")


if __name__ == "__main__":
    main()
