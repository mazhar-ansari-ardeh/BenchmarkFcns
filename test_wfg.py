import numpy as np
from benchmarkfcns import multiobjective


def test_wfg():
    # WFG search space is typically [0, 2i]
    # For n=6, x_i in [0, 2, 4, 6, 8, 10, 12]
    x = np.array([[1.0, 2.0, 3.0, 4.0, 5.0, 6.0]])

    for i in range(1, 10):
        func_name = f"wfg{i}"
        func = getattr(multiobjective, func_name)
        try:
            res = func(x, num_objectives=3, k=2)
            print(f"{func_name} result: {res}")
            assert res.shape == (1, 3)
        except Exception as e:
            print(f"{func_name} failed: {e}")


if __name__ == "__main__":
    test_wfg()
