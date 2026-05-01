from __future__ import annotations
import numpy as np
from .composition import Composition


def get_cec_data(f_id: int, dimensions: int, num_components: int = 1):
    """
    Generates reproducible shift and rotation data for CEC 2005 functions.
    In a real competition setting, these would be loaded from .txt files.
    """
    rng = np.random.default_rng(f_id * 1000 + dimensions)
    shifts = [rng.uniform(-50, 50, dimensions) for _ in range(num_components)]
    rotations = [
        np.eye(dimensions) for _ in range(num_components)
    ]  # Default to identity
    return shifts, rotations


# Unimodal Functions (F1-F5)
def f1(dimensions: int) -> Composition:
    """Shifted Sphere Function"""
    shifts, _ = get_cec_data(1, dimensions)
    comp = Composition()
    comp.add("sphere", shifts[0], bias=-450.0)
    return comp


def f2(dimensions: int) -> Composition:
    """Shifted Schwefel 1.2 Function"""
    shifts, _ = get_cec_data(2, dimensions)
    comp = Composition()
    comp.add("schwefel12", shifts[0], bias=-450.0)
    return comp


def f3(dimensions: int) -> Composition:
    """Shifted Rotated Elliptic Function"""
    shifts, rotations = get_cec_data(3, dimensions)
    comp = Composition()
    comp.add("elliptic", shifts[0], rotation=rotations[0], bias=-450.0)
    return comp


def f4(dimensions: int) -> Composition:
    """Shifted Schwefel 1.2 Function with Noise"""
    shifts, _ = get_cec_data(4, dimensions)
    comp = Composition()
    # Note: Noise is usually added at evaluation time.
    comp.add("schwefel12", shifts[0], bias=-450.0)
    return comp


def f5(dimensions: int) -> Composition:
    """Schwefel 2.6 with Global Optimum on Bounds"""
    shifts, _ = get_cec_data(5, dimensions)
    comp = Composition()
    comp.add("schwefel", shifts[0], bias=-310.0)
    return comp


# Basic Multimodal Functions (F6-F12)
def f6(dimensions: int) -> Composition:
    """Shifted Rosenbrock Function"""
    shifts, _ = get_cec_data(6, dimensions)
    comp = Composition()
    comp.add("rosenbrock", shifts[0], bias=390.0)
    return comp


def f7(dimensions: int) -> Composition:
    """Shifted Rotated Griewank Function"""
    shifts, rotations = get_cec_data(7, dimensions)
    comp = Composition()
    comp.add("griewank", shifts[0], rotation=rotations[0], bias=-180.0)
    return comp


def f8(dimensions: int) -> Composition:
    """Shifted Rotated Ackley Function"""
    shifts, rotations = get_cec_data(8, dimensions)
    comp = Composition()
    comp.add("ackley", shifts[0], rotation=rotations[0], bias=-140.0)
    return comp


def f9(dimensions: int) -> Composition:
    """Shifted Rastrigin Function"""
    shifts, _ = get_cec_data(9, dimensions)
    comp = Composition()
    comp.add("rastrigin", shifts[0], bias=-330.0)
    return comp


def f10(dimensions: int) -> Composition:
    """Shifted Rotated Rastrigin Function"""
    shifts, rotations = get_cec_data(10, dimensions)
    comp = Composition()
    comp.add("rastrigin", shifts[0], rotation=rotations[0], bias=-330.0)
    return comp


def f11(dimensions: int) -> Composition:
    """Shifted Rotated Weierstrass Function"""
    shifts, rotations = get_cec_data(11, dimensions)
    comp = Composition()
    comp.add("weierstrass", shifts[0], rotation=rotations[0], bias=90.0)
    return comp


def f12(dimensions: int) -> Composition:
    """Schwefel 2.13"""
    shifts, _ = get_cec_data(12, dimensions)
    comp = Composition()
    comp.add("schwefel", shifts[0], bias=-460.0)
    return comp


def f13(dimensions: int) -> Composition:
    """Expanded Griewank plus Rosenbrock (F8F2)"""
    shifts, _ = get_cec_data(13, dimensions)
    comp = Composition()
    comp.add("f8f2", shifts[0], bias=-130.0)
    return comp


def f14(dimensions: int) -> Composition:
    """Shifted Rotated Expanded Scaffer F6"""
    shifts, rotations = get_cec_data(14, dimensions)
    comp = Composition()
    comp.add("schafferf6", shifts[0], rotation=rotations[0], bias=-300.0)
    return comp


# Hybrid Composition Functions (F15-F25)
def _hybrid_factory(
    f_id: int,
    dimensions: int,
    base_fcns: list[str],
    biases: list[float],
    sigmas: list[float],
    f_bias: float,
) -> Composition:
    shifts, rotations = get_cec_data(f_id, dimensions, num_components=len(base_fcns))
    comp = Composition()
    for i in range(len(base_fcns)):
        comp.add(
            base_fcns[i],
            shifts[i],
            rotation=rotations[i],
            sigma=sigmas[i],
            lambda_val=1.0,
            bias=biases[i],
            f_max=10.0,
        )
    return comp


def f15(dimensions: int) -> Composition:
    """Hybrid Composition Function 1"""
    base = (
        ["rastrigin"] * 2
        + ["weierstrass"] * 2
        + ["griewank"] * 2
        + ["ackley"] * 2
        + ["sphere"] * 2
    )
    biases = [i * 100 for i in range(10)]
    sigmas = [1.0] * 10
    return _hybrid_factory(15, dimensions, base, biases, sigmas, 120.0)


def f18(dimensions: int) -> Composition:
    """Rotated Hybrid Composition Function 2"""
    base = (
        ["rastrigin"] * 2
        + ["weierstrass"] * 2
        + ["griewank"] * 2
        + ["ackley"] * 2
        + ["sphere"] * 2
    )
    biases = [i * 100 for i in range(10)]
    sigmas = [1.0, 2.0, 1.5, 1.5, 1.0, 1.0, 2.0, 2.0, 1.5, 1.5]
    return _hybrid_factory(18, dimensions, base, biases, sigmas, 10.0)


def f21(dimensions: int) -> Composition:
    """Rotated Hybrid Composition Function 3"""
    base = (
        ["f8f2"] * 2
        + ["weierstrass"] * 2
        + ["griewank"] * 2
        + ["ackley"] * 2
        + ["sphere"] * 2
    )
    biases = [i * 100 for i in range(10)]
    sigmas = [1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0]
    return _hybrid_factory(21, dimensions, base, biases, sigmas, 360.0)


def f24(dimensions: int) -> Composition:
    """Rotated Hybrid Composition Function 4"""
    base = (
        ["weierstrass"] * 2
        + ["rastrigin"] * 2
        + ["griewank"] * 2
        + ["ackley"] * 2
        + ["sphere"] * 2
    )
    biases = [i * 100 for i in range(10)]
    sigmas = [1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0]
    return _hybrid_factory(24, dimensions, base, biases, sigmas, 260.0)
