"""
An implementation of the Artificial Bee Colony algorithm.

Artificial Bee Colony was first Proposed by Dervis Karaboga in:
D. Dervis Karaboga, An Idea Based On Honey Bee Swarm for Numerical
Optimization, Technical Report-TR06,Erciyes University, Engineering
Faculty, Computer Engineering Department 2005.

Author: Mazhar Ansari Ardeh
Please forward any comments or bug reports to mazhar.ansari.ardeh at
Googles e-mail service or feel free to kindly modify the repository.
"""

from __future__ import annotations

import logging
import random

import numpy as np


class FoodSources:
    """
    The class implements the logic for managing the food sources of the Artificial Bee
    Colony algorithm.
    """

    def __init__(
        self,
        a_problem,
        dimension: int,
        food_number,
        limit,
        lower_bound,
        upper_bound,
        initial_population=None,
    ):
        """
        Initialises a new food source object.
        Parameters:
        - a_problem: A problem to be optimised.
        - dimension: The dimension of problem that is being solved.
        - food_number: The number of food items (i.e. the population size of the algorithm).
        - limit: A food source which could not be improved through "limit" trials is abandoned by
                   its employed bee.
        - lower_bound: The lower bound of the problem space.
        - upper_bound: The upper bound of the problem space.
        - initial_population: The initial population

        """
        if initial_population is None:
            initial_population = []
        elif not initial_population:
            assert (
                dimension == initial_population.shape[1]
            ), "Given Dimension does not match given initial population"
            assert (
                food_number == initial_population.shape[0]
            ), "Given food source size does not match initial population"
        self.problem = a_problem
        self.dimension = dimension
        self.food_number = food_number
        self.limit = limit

        # Represents all food sources. Foods is the population of food sources. Each row of
        # Foods matrix is a vector holding D parameters to be optimized. The number of rows of
        # Foods matrix equals to the this.food_source.food_number
        self.foods = np.zeros((food_number, dimension))
        self.of_value = np.zeros(food_number)
        self.fitness = np.zeros(food_number)
        self.trial = np.zeros(food_number)
        self.prob = np.zeros(food_number)
        self.solution = np.zeros(dimension)
        self.params_of_global_min = np.zeros(dimension)
        self.lower_bound = lower_bound
        self.upper_bound = upper_bound
        self.stall_counter = 0
        self.initialize_food_sources(initial_population)
        self.obj_val_of_global_min = np.min(self.of_value)
        self.params_of_global_min = self.foods[
            self.of_value == self.obj_val_of_global_min, :
        ]

    def initialize_food_sources(self, initial_population):
        """
        Initialise the food source. If `initial_population` is `None`, the population
        is generated randomly.

        Parameters:
        -----------
        - initial_population: The initial population.
        Returns:
        --------
        None
        """
        if initial_population is None or len(initial_population) != 0:
            self.foods = initial_population
            for index in range(initial_population.shape[0]):
                self.of_value[index] = self.problem(self.foods[index, :])
                self.fitness[index] = self.calculate_fitness(self.of_value[index])
            return
        for i in range(self.food_number):
            self.new_food_source(i)
            self.obj_val_of_global_min = self.of_value[0]
            self.params_of_global_min = self.foods[0, :]

    def new_food_source(self, index):
        """
        Creates a new food source randomly and evaluates on with the objective function.
        Parameters:
        -----------
        - index: the index of the food source.
        Returns:
        --------
        None
        """
        for j in range(self.dimension):
            rnd = random.random() * 32767 / (32767 + 1)
            self.foods[index, j] = (
                rnd * (self.upper_bound[j] - self.lower_bound[j]) + self.lower_bound[j]
            )
        self.of_value[index] = self.problem(self.foods[index, :])
        self.fitness[index] = self.calculate_fitness(self.of_value[index])
        self.trial[index] = 0

    def calculate_fitness(self, fun):
        """
        Calculates the normalised fitness value.
        Parameters:
        -----------
        - fun: The fitness value.
        """
        if fun >= 0:
            return 1 / (fun + 1)
        return 1 + abs(fun)

    def calculate_probabilities(self):
        """
        Calculates the probabilities for each fitness value in the population.
        :return: None
        """
        max_fit = max(self.fitness)
        self.prob = (0.9 * (self.fitness / max_fit)) + 0.1
        return self

    def memorize_best_source(self):
        """
        Finds and records the best fitness value found so far.
        """
        min_of_val = min(self.of_value)
        if min_of_val < self.obj_val_of_global_min:
            # Update the global minimum value and its parameters
            self.obj_val_of_global_min = min_of_val
            self.params_of_global_min = self.foods[
                self.of_value == self.obj_val_of_global_min, :
            ]
            self.stall_counter = 0
        else:
            # Increment the stall counter if no better solution is found
            self.stall_counter = self.stall_counter + 1
        return self

    def create_food_source_randomly_from(self, from_idx):
        """
        Creates a new random food source around another food source.
        Parameters:
        - from_idx: The index of the other food source that the new food source should be
            created based on.
        """
        # Set the dimension of the problem
        dim = self.dimension

        # Generate a random parameter index to change
        rnd = random.random() * 32767 / (32767 + 1)
        param2change = int(rnd * dim)

        # Generate a random neighbour index
        rnd = random.random() * 32767 / (32767 + 1)
        neighbour = int(rnd * self.food_number)

        # Make sure the neighbour is different from the current solution
        while neighbour == from_idx:
            rnd = random.random() * 32767 / (32767 + 1)
            neighbour = int(rnd * self.food_number)

        # Create a copy of the current solution
        solution = self.foods[from_idx].copy()

        # Generate a new parameter value based on the current solution and the random neighbour
        rnd = random.random() * 32767 / (32767 + 1)
        solution[param2change - 1] = (
            self.foods[from_idx, param2change - 1]
            + (
                self.foods[from_idx, param2change - 1]
                - self.foods[neighbour, param2change - 1]
            )
            * (rnd - 0.5)
            * 2
        )

        # If the generated parameter value is out of boundaries, shift it onto the boundaries
        if solution[param2change - 1] > self.upper_bound[param2change - 1]:
            solution[param2change - 1] = self.upper_bound[param2change - 1]
        if solution[param2change - 1] < self.lower_bound[param2change - 1]:
            solution[param2change - 1] = self.lower_bound[param2change - 1]

        return solution


def abc(func, nvar, lower_bound=None, upper_bound=None, setting=None):
    """
    Optimizes a given function with the Artificial Bee Colony algorithm (ABC).
    Artificial Bee Colony was first Proposed by Dervis Karaboga in:
    D. Dervis Karaboga, An Idea Based On Honey Bee Swarm for Numerical
    Optimization, Technical Report-TR06, Erciyes University, Engineering
    Faculty, Computer Engineering Department 2005.
    Parameters:
    -----------
        func: a function to find the minimum of. `func` should accept a vector of size 1-by-nvar,
        and returns a scalar evaluated at the given point.
        nvar: is the dimension (number of design variables) of `func`.
        lower_bound: defines a set of lower bounds on the design variables.
        upper_bound: defines a set of upper bounds on the design variables.
        setting: Specifies the optimisation parameters of the algorithm. `setting` can be created
        with the `abcoptions` method.
    Returns:
    x: a vector of shape 1-by-nvar of the found global minimum point of `func`.
    fval: the value of the fitness function `func` at the solution `x`.
    generations: a matrix that contains the the food source at each iteration of the
        algorithm that had the best fitness at that generation.
    fval_generations: the value of the best fitness at each iteration of the algorithm.
    population: an array that contains values for population (food sources) of the algorithm at each
    iterations.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Googles e-mail service or feel free to kindly modify the repository.
    """
    if nvar <= 0:
        msg = "Dimension cannot be zero or negative"
        raise ValueError(msg)

    if upper_bound is None:
        upper_bound = np.array([np.iinfo(np.int32).max] * nvar)
    if lower_bound is None:
        lower_bound = np.array([np.iinfo(np.int32).min] * nvar)

    exc_msg = ""
    if lower_bound.size == 0 or upper_bound.size == 0:
        exc_msg = "Bounds cannot be empty"
        raise ValueError(exc_msg)
    if lower_bound.shape != upper_bound.shape:
        exc_msg = "Dimensions of bounds mismatch"
        raise ValueError(exc_msg)
    if lower_bound.ndim != 1 or upper_bound.ndim != 1:
        exc_msg = "Bounds must be a vector"
        raise ValueError(exc_msg)

    if lower_bound.shape[0] != nvar:
        lower_bound = lower_bound.reshape(1, lower_bound.shape[0])
    if upper_bound.shape[0] != nvar:
        upper_bound = upper_bound.reshape(1, upper_bound.shape[0])

    if setting is None:
        setting = abcoptions("default")

    max_iter = setting["Generations"]
    initial_population = setting["initial_population"]
    limit = setting["Limit"]
    food_number = setting["PopulationSize"]

    food_source = FoodSources(
        func, nvar, food_number, limit, lower_bound, upper_bound, initial_population
    )

    generations = np.zeros((max_iter, nvar))
    fval_generations = np.zeros((max_iter, 1))
    populations = [None] * max_iter

    for i in range(max_iter):
        food_source = send_employed_bees(func, food_source)
        food_source = send_onlooker_bees(func, food_source)
        food_source = food_source.memorize_best_source()
        food_source = send_scout_bees(food_source)

        display(setting, i, food_source.obj_val_of_global_min)

        generations[i, :] = food_source.params_of_global_min
        fval_generations[i] = food_source.obj_val_of_global_min
        populations[i] = food_source.foods

        if food_source.stall_counter > setting["StallLimit"]:
            break

    x_best = food_source.params_of_global_min
    f_best = food_source.obj_val_of_global_min

    return x_best, f_best, generations, fval_generations, populations


def display(setting, iteration, fval):
    """
    Prints information about the optimization process.

    Parameters:
    -----------
    - setting: A dictionary containing the settings for the optimization process.
    - iteration: The current iteration number.
    - fval: The current function value.
    """
    display_setting = setting["Display"]
    if display_setting == "off":
        return
    if display_setting == "iter":
        msg = f"Generation: {iteration}\t f(x): {fval}"
        logging.info(msg)
        # update the figure if using matplotlib or other plotting library
        return
    if display_setting == "final" and iteration == setting["Generations"]:
        msg = f"Generation: {iteration}\t f(x): {fval}"
        logging.info(msg)


def send_scout_bees(food_source):
    """
    Determines the food sources whose trial counter exceeds the "limit" value.
    In Basic ABC, only one scout is allowed to occur in each cycle.

    Parameters:
    - food_source (dict): A dictionary containing food source information including 'trial'
        and 'limit'

    Returns:
    - dict: A dictionary containing food source information after checking and updating scout bees
    """
    maxtrialindex = np.argmax(food_source.trial)
    if food_source.trial[maxtrialindex] >= food_source.limit:
        food_source.new_food_source(maxtrialindex)
    return food_source


def send_onlooker_bees(func, food_source):
    """
    Dispatch the onlooker bees.
    Parameters:
    - func: The function to be optimised.
    - food_source: The food source

    Returns:
    --------
    - The food source.
    """
    food_source = food_source.calculate_probabilities()
    i = 0
    counter = 0
    while counter <= food_source.food_number:
        rnd = random.random() * 32767 / (32767 + 1)
        if (
            rnd < food_source.prob[i]
        ):  # choose a food source depending on its probability to be chosen
            counter += 1
            solution = food_source.create_food_source_randomly_from(i)
            obj_val_sol = func(solution)
            fitness_sol = food_source.calculate_fitness(obj_val_sol)
            if fitness_sol > food_source.fitness[i]:
                # If the mutant solution is better than the current solution i, replace the
                # solution with the mutant and reset the trial counter of solution i.
                food_source.trial[i] = 0
                food_source.foods[i, :] = solution
                food_source.of_value[i] = obj_val_sol
                food_source.fitness[i] = fitness_sol
            else:
                # if the solution i can not be improved, increase its trial counter.
                food_source.trial[i] += 1
        i += 1
        if i == food_source.food_number:
            i = 0

    return food_source


def send_employed_bees(func, food_source):
    """
    Dispatch the bees to find the best source.
    Parameters:
    -----------
    - food_source: The collection of food sources.
    Returns:
    --------
    - food_source: The collection of food sources.
    """
    for i in range(food_source.food_number):
        # create a new food source randomly from the current solution
        solution = food_source.create_food_source_randomly_from(i)
        # evaluate the objective value of the new solution
        obj_val_sol = func(solution)
        # calculate the fitness value of the new solution
        fitness_sol = food_source.calculate_fitness(obj_val_sol)
        if fitness_sol > food_source.fitness[i]:
            food_source.trial[i] = 0
            food_source.foods[i, :] = solution
            food_source.of_value[i] = obj_val_sol
            food_source.fitness[i] = fitness_sol
        else:
            # if the solution i can not be improved, increase its trial counter
            food_source.trial[i] += 1
    return food_source


def abcoptions(*varargin):
    """
    Creates an option structure for Artificial Bee Colony algorithm.
    The function will print the list of available options and their values.
    OPTIONS = `abcoptions`('default') will return an option structure that
    contains default values for the algorithm parameters.
    OPTIONS = `abcoptions`('list') will print the list of available options and
    their values.
    OPTIONS = `abcoptions`('PARAM',VALUE) creates a structure with the default
    parameters used for all PARAM not specified, and will use the passed
    argument VALUE for the specified PARAM.

    Warning: Validity of PARAMs are not checked.
    """

    if len(varargin) == 0:
        return """
        initial_population  : [matrix]
        Generations        : [positive scalar | "200"]
        Display            : ['off' | 'iter' | 'final']
        PopulationSize     : [positive scalar | "200"]
        Limit              : [positive scalar | "10"]
        StallLimit         : [positive scalar | "Inf"]
        """

    if len(varargin) == 1 and isinstance(varargin[0], str):
        if varargin[0].lower() == "default":
            return {
                "initial_population": None,
                "Generations": 200,
                "Display": "off",
                "PopulationSize": 200,
                "Limit": 10,
                "StallLimit": float("inf"),
            }
        if varargin[0].lower() == "list":
            return abcoptions()

    setting = {
        "initial_population": None,
        "Generations": 200,
        "Display": "off",
        "PopulationSize": 200,
        "Limit": 10,
        "StallLimit": float("inf"),
    }
    # At this moment, the validity of input data is not checked. BAD IDEA!!
    for i in range(0, len(varargin), 2):
        setting[varargin[i]] = varargin[i + 1]

    return setting
