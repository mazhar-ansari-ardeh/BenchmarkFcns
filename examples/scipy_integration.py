from scipy.optimize import differential_evolution
from benchmarkfcns import ackley
import time


# With vectorized=True, SciPy passes the entire population as an (M, N) matrix.
# This perfectly matches the BenchmarkFcns C++ backend, enabling OpenMP parallelization.
def objective_vectorized(x):
    # x is already (M, N), so we just pass it directly
    return ackley(x)


if __name__ == "__main__":
    dimensions = 20
    bounds = [(-32, 32)] * dimensions

    print(
        f"Starting VECTORIZED SciPy Differential Evolution on {dimensions}D Ackley..."
    )

    start = time.time()
    # Setting vectorized=True is the key to high performance here
    result = differential_evolution(
        objective_vectorized, bounds, vectorized=True, popsize=1000
    )
    end = time.time()

    print("\nOptimization Results:")
    print(f"Global Minimum Value: {result.fun}")
    print(f"Time Taken: {end - start:.4f} seconds")
    print(f"Success: {result.success}")
