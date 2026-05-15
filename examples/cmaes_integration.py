import cma
from benchmarkfcns import elliptic
import numpy as np


# benchmarkfcns expects a 2D array (M-by-N).
def objective(x):
    return elliptic(x.reshape(1, -1))[0]


if __name__ == "__main__":
    dimensions = 10
    x0 = np.random.uniform(-5, 5, dimensions)  # Initial guess
    sigma0 = 0.5  # Initial step size

    print(f"Starting CMA-ES on {dimensions}D Elliptic function...")

    # Run the optimizer
    es = cma.fmin(
        objective, x0, sigma0, options={"bounds": [-100, 100], "maxiter": 1000}
    )

    print("\nOptimization Results:")
    print(f"Global Minimum Value: {es[1]}")
    print(f"Best Coordinates: {es[0]}")
