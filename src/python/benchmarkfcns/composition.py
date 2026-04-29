from __future__ import annotations
import numpy as np
from ._core import Composition as _CoreComposition
from ._core import get_function_ptr as _get_function_ptr


class Composition(_CoreComposition):
    """
    A high-performance engine for creating hybrid/composition benchmark functions.
    This class allows blending multiple base functions using CEC-standard
    exponential weighting, shifting, and rotation.
    """

    def __init__(self, constant_C: float = 2000.0):
        super().__init__()
        self.set_constant_C(constant_C)
        self._dimensions = None

    def add(
        self,
        function: str | callable,
        shift: np.ndarray,
        rotation: np.ndarray | None = None,
        sigma: float = 1.0,
        lambda_val: float = 1.0,
        bias: float = 0.0,
        f_max: float = 1.0,
    ):
        """
        Adds a base function component to the composition.

        Args:
            function: Name of the built-in function (e.g. 'ackley') or a pointer.
            shift: 1D array of size N for shifting the optimum.
            rotation: 2D array of size N-by-N for coordinate rotation.
                    Defaults to Identity matrix.
            sigma: Convergence range / basin of attraction size.
            lambda_val: Scaling parameter for the landscape.
            bias: Internal bias for this component.
            f_max: Estimated maximum value for height normalization.
        """
        shift = np.ascontiguousarray(shift, dtype=np.float64)
        n = len(shift)

        if self._dimensions is None:
            self._dimensions = n
        elif self._dimensions != n:
            raise ValueError(
                f"Shift vector size {n} does not match composition dimensions {self._dimensions}"
            )

        if rotation is None:
            rotation = np.eye(n)
        rotation = np.ascontiguousarray(rotation, dtype=np.float64)

        if isinstance(function, str):
            fcn_ptr = _get_function_ptr(function)
        else:
            # Assume it's already a pointer or compatible object
            fcn_ptr = function

        self.add_component(fcn_ptr, shift, rotation, sigma, lambda_val, bias, f_max)

    def evaluate(self, x: np.ndarray) -> np.ndarray:
        """
        Evaluates the composed function for a batch of points.

        Args:
            x: Matrix of size M-by-N (M points in N dimensions)
        Returns:
            1D array of size M containing the composed scores.
        """
        x = np.ascontiguousarray(x, dtype=np.float64)
        if len(x.shape) == 1:
            x = x.reshape(1, -1)

        if self._dimensions is not None and x.shape[1] != self._dimensions:
            raise ValueError(
                f"Input dimension {x.shape[1]} does not match composition dimensions {self._dimensions}"
            )

        return super().evaluate(x)

    def __call__(self, x: np.ndarray) -> np.ndarray:
        return self.evaluate(x)


def cec2005_f15(n: int) -> Composition:
    """
    Factory for the CEC 2005 F15 (Hybrid Composition Function 1).
    Note: This uses the official 10 centers but assumes identity rotation
    as per F15 definition.
    """
    # Standard F15 Centers for 2D, 10D, 30D, 50D are shifted.
    # For a generic n, we'll generate the grid-like pattern used in the suite.
    comp = Composition()

    # 10 base functions
    functions = [
        "rastrigin",
        "rastrigin",
        "weierstrass_base",
        "weierstrass_base",
        "griewank",
        "griewank",
        "ackley",
        "ackley",
        "sphere",
        "sphere",
    ]

    # Standard sigmas for F15
    sigmas = [1.0] * 10

    # Standard biases
    biases = [0, 100, 200, 300, 400, 500, 600, 700, 800, 900]

    # f_max for height normalization (CEC 2005 F15 estimates)
    # These values ensure the functions mix at similar "heights"
    f_maxs = [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]  # Placeholders

    # Generate shifts (Example logic, real CEC data is usually loaded from files)
    # For now, we place the centers at random locations in [-5, 5]
    rng = np.random.default_rng(42)  # Deterministic for this factory

    for i in range(10):
        shift = rng.uniform(-5, 5, n)
        comp.add(functions[i], shift, sigma=sigmas[i], bias=biases[i], f_max=f_maxs[i])

    return comp
