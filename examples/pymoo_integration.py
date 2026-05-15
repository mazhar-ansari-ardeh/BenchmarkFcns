from pymoo.optimize import minimize
from pymoo.core.problem import Problem
from pymoo.algorithms.moo.nsga2 import NSGA2
from benchmarkfcns import multiobjective


# Using 'Problem' instead of 'ElementwiseProblem' enables vectorized evaluation.
# The algorithm passes the entire population as a matrix.
class ZDT1ProblemVectorized(Problem):
    def __init__(self, n_var=30):
        super().__init__(n_var=n_var, n_obj=2, xl=0.0, xu=1.0)

    def _evaluate(self, x, out, *args, **kwargs):
        # x is (M, N). multiobjective.zdt1 accepts this and returns (M, 2).
        # The C++ core handles the parallel evaluation of all M points.
        out["F"] = multiobjective.zdt1(x)


if __name__ == "__main__":
    problem = ZDT1ProblemVectorized()
    algorithm = NSGA2(pop_size=100)

    print("Starting VECTORIZED Pymoo NSGA-II on ZDT1...")

    res = minimize(problem, algorithm, ("n_gen", 100), seed=1, verbose=False)

    print("\nOptimization Results:")
    print(f"Number of Pareto-optimal solutions: {len(res.F)}")
    print(f"First 5 objective scores:\n{res.F[:5]}")
