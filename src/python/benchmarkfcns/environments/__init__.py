from __future__ import annotations
from .core import BenchmarkEnv
import benchmarkfcns
from typing import Any


def make(
    id: str,
    dimensions: int = 2,
    max_steps: int = 100,
    target_value: float | None = None,
    relative_actions: bool = False,
    step_size: float = 0.1,
    **kwargs: Any,
) -> BenchmarkEnv:
    """
    Create a Gymnasium environment for a benchmark function.

    Args:
        id: The name of the benchmark function (e.g. 'ackley').
        dimensions: Dimensionality of the problem.
        max_steps: Maximum number of steps per episode.
        target_value: Optional target value for termination.
        relative_actions: If True, actions are interpreted as displacements.
        step_size: Scaling factor for relative actions.
        **kwargs: Additional arguments for the benchmark function.

    Returns:
        A BenchmarkEnv instance.
    """
    func = getattr(benchmarkfcns, id)

    # Try to determine default bounds from function attributes if they exist
    # In BenchmarkFcns, most functions don't have bounds as attributes yet,
    # but we can add common ones here.

    defaults = {
        "ackley": (-32.768, 32.768),
        "rastrigin": (-5.12, 5.12),
        "rosenbrock": (-5.0, 10.0),
        "sphere": (-5.12, 5.12),
        "griewank": (-600.0, 600.0),
        "schwefel": (-500.0, 500.0),
    }

    low, high = defaults.get(id, (-100.0, 100.0))

    # If kwargs contains bounds, override
    low = kwargs.pop("low", low)
    high = kwargs.pop("high", high)

    # Create a wrapper function that handles kwargs
    if kwargs:

        def wrapped_func(x):
            return func(x, **kwargs)
    else:
        wrapped_func = func

    return BenchmarkEnv(
        func=wrapped_func,
        low=low,
        high=high,
        dimensions=dimensions,
        max_steps=max_steps,
        target_value=target_value,
        relative_actions=relative_actions,
        step_size=step_size,
    )


__all__ = ["BenchmarkEnv", "make"]

# Standardized registration for Gymnasium
try:
    from gymnasium.envs.registration import register

    # Common benchmark functions to register
    _standard_functions = [
        "ackley",
        "rastrigin",
        "rosenbrock",
        "sphere",
        "griewank",
        "schwefel",
        "levy",
        "michalewicz",
        "zakharov",
        "dixonprice",
    ]

    for func_name in _standard_functions:
        register(
            id=f"BenchmarkFcns/{func_name.capitalize()}-v0",
            entry_point="benchmarkfcns.environments:make",
            kwargs={"id": func_name},
        )
except ImportError:
    # Gymnasium not installed
    pass
