import pytest
import numpy as np
import benchmarkfcns

# Format: (function_name, optimum_coords, expected_value)
CLASSIC_OPTIMA = [
    ("ackley", [0, 0, 0], 0.0),
    ("rastrigin", [0, 0, 0], 0.0),
    ("sphere", [0, 0, 0], 0.0),
    ("rosenbrock", [1, 1, 1], 0.0),
    ("griewank", [0, 0, 0], 0.0),
    ("zakharov", [0, 0, 0], 0.0),
    ("sumsquares", [0, 0, 0], 0.0),
    ("brown", [0, 0, 0], 0.0),
    ("exponential", [0, 0, 0], -1.0),
    ("step", [0, 0, 0], 0.0),
    ("levy", [1, 1, 1], 0.0),
    ("michalewicz", [2.20290552, 1.57079633], -1.80130341),
    ("beale", [3, 0.5], 0.0),
    ("booth", [1, 3], 0.0),
    ("matyas", [0, 0], 0.0),
    ("goldsteinprice", [0, -1], 3.0),
]


def test_multiobjective_zdt():
    """Verify standard multi-objective ZDT1 function."""
    from benchmarkfcns import multiobjective

    x = np.zeros((1, 30))  # ZDT1 is 30D by default
    res = multiobjective.zdt1(x)
    assert res.shape == (1, 2)
    # At x=0, f1=0, g=1, h=1 -> f2=1
    assert res[0, 0] == pytest.approx(0.0)
    assert res[0, 1] == pytest.approx(1.0)


@pytest.mark.parametrize("func_name, coords, expected", CLASSIC_OPTIMA)
def test_global_optima(func_name, coords, expected):
    """Verify that common functions return the correct value at their known global optimum."""
    func = getattr(benchmarkfcns, func_name)
    x = np.array([coords], dtype=np.float64)
    result = func(x)

    assert result.shape == (1,)
    # Use approx for floating point precision issues
    assert result[0] == pytest.approx(expected, abs=1e-7)


def test_batch_consistency():
    """Verify that batch evaluation (M points at once) matches individual evaluations."""
    func = benchmarkfcns.ackley
    n_points = 50
    dims = 10

    # Create random data
    data = np.random.uniform(-5, 5, (n_points, dims))

    # Evaluate as a batch
    batch_results = func(data)

    # Evaluate individually
    individual_results = np.array([func(data[i : i + 1])[0] for i in range(n_points)])

    assert batch_results.shape == (n_points,)
    assert np.allclose(batch_results, individual_results, atol=1e-12)


def test_high_dimensionality():
    """Verify functions can handle varying dimensions (e.g. 100D)."""
    dims = 100
    x = np.zeros((1, dims))

    # These should all succeed without crashing
    assert benchmarkfcns.sphere(x)[0] == pytest.approx(0.0)
    assert benchmarkfcns.rastrigin(x)[0] == pytest.approx(0.0)
    assert benchmarkfcns.ackley(x)[0] == pytest.approx(0.0)


def test_input_types():
    """Verify functions accept lists, tuples, and numpy arrays."""
    # List of lists
    res1 = benchmarkfcns.sphere([[0, 0]])
    # Numpy array
    res2 = benchmarkfcns.sphere(np.array([[0, 0]]))

    assert res1[0] == res2[0] == 0.0
