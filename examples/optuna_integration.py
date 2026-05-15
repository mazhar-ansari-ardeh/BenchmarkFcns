import optuna
from benchmarkfcns import rosenbrock
import numpy as np


def objective(trial, dims=5):
    # Define the search space for each dimension
    x = np.array([trial.suggest_float(f"x{i}", -5, 5) for i in range(dims)])

    # Evaluate using the high-performance C++ backend
    return rosenbrock(x.reshape(1, -1))[0]


if __name__ == "__main__":
    dims = 5
    print(f"Starting Optuna Study on {dims}D Rosenbrock function...")

    # Create a study to minimize the function
    study = optuna.create_study(direction="minimize")
    study.optimize(lambda trial: objective(trial, dims=dims), n_trials=500)

    print("\nOptimization Results:")
    print(f"Best Value: {study.best_value}")
    print(f"Best Params: {study.best_params}")
