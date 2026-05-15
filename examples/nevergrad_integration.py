import nevergrad as ng
from benchmarkfcns import rastrigin


# benchmarkfcns expects a 2D array (M-by-N).
def objective(x):
    # Nevergrad passes coordinates as individual arguments or a list depending on setup.
    # Here we assume a list/array input.
    return rastrigin(x.reshape(1, -1))[0]


if __name__ == "__main__":
    dimensions = 5

    # Define the parametrization (search space)
    parametrization = ng.p.Array(shape=(dimensions,)).set_bounds(
        lower=-5.12, upper=5.12
    )

    # Choose an optimizer (NGOpt is a powerful meta-optimizer)
    optimizer = ng.optimizers.registry["NGOpt"](
        parametrization=parametrization, budget=1000
    )

    print(f"Starting Nevergrad NGOpt on {dimensions}D Rastrigin function...")

    recommendation = optimizer.minimize(objective)

    print("\nOptimization Results:")
    print(f"Global Minimum Value: {recommendation.loss}")
    print(f"Best Coordinates: {recommendation.value}")
