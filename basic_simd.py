import random
from time import perf_counter
from deap import base, creator, tools
from benchmarkfcns import ackley


# Define the optimization problem: minimize a function
# Example function: Sphere function (f(x) = sum(x_i^2) for all dimensions)
def evaluate(individual):
    return ackley(individual)
    # return sum(x**2 for x in individual),


# Set up DEAP components
creator.create("FitnessMin", base.Fitness, weights=(-1.0,))  # Minimize the function
creator.create("Particle", list, fitness=creator.FitnessMin, speed=list, best=None)


# Initialize particles
def generate_particle(size, low, up):
    particle = creator.Particle(random.uniform(low, up) for _ in range(size))
    particle.speed = [random.uniform(-1, 1) for _ in range(size)]
    particle.best = None
    return particle


# Update particle position and velocity
def update_particle(particle, best_global, phi1, phi2, w):
    for i, value in enumerate(particle):
        r1, r2 = random.random(), random.random()
        particle.speed[i] = (
            w * particle.speed[i]
            + phi1 * r1 * (particle.best[i] - value)
            + phi2 * r2 * (best_global[i] - value)
        )
        particle[i] += particle.speed[i]


# Main function
def main():
    # Problem settings
    dimensions = 3  # Number of dimensions
    low, up = -10, 10  # Bounds for each dimension
    n_particles = 400000  # Number of particles
    max_generations = 100  # Maximum number of generations

    # PSO hyperparameters
    w = 0.7  # Inertia weight
    phi1 = 1  # Personal attraction coefficient
    phi2 = 1  # Global attraction coefficient

    # Toolbox
    toolbox = base.Toolbox()
    toolbox.register("particle", generate_particle, size=dimensions, low=low, up=up)
    toolbox.register("population", tools.initRepeat, list, toolbox.particle)
    toolbox.register("evaluate", evaluate)
    toolbox.register("update", update_particle)

    # Create population
    population = toolbox.population(n=n_particles)

    # Initialize global best
    best_global = None
    best_global_fitness = float("inf")

    # PSO loop
    for generation in range(max_generations):
        scores = toolbox.evaluate(population)
        i = 0
        for particle in population:
            # Evaluate fitness
            particle.fitness.values = (scores[i],)
            i += 1
            # particle.fitness.values = toolbox.evaluate(particle)

            # Update personal best
            if not particle.best or particle.fitness.values[0] < particle.best[0]:
                particle.best = particle[:]

            # Update global best
            if particle.fitness.values[0] < best_global_fitness:
                best_global = particle[:]
                best_global_fitness = particle.fitness.values[0]

        # Update particles
        for particle in population:
            toolbox.update(particle, best_global, phi1, phi2, w)

        # Print progress
        if generation % 10 == 0:
            print(f"Generation {generation}: Best Fitness = {best_global_fitness}")

    print("Optimization finished.")
    print(f"Best Solution: {best_global}, Best Fitness: {best_global_fitness}")


if __name__ == "__main__":
    tic = perf_counter()
    main()
    toc = perf_counter()
    print(f"Optimization took {toc - tic}")
