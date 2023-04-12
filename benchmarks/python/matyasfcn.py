import numpy as np

def matyasfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Matyas benchmark function.

    Args:
        x (numpy.ndarray): Input matrix of size M-by-2.

    Returns:
    --------
        numpy.ndarray: Vector of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    The Matyas function is only defined on a 2D space. For more information,
    please visit: https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Matyas's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]

    scores = 0.26 * (X ** 2 + Y ** 2) - 0.48 * X * Y
    return scores
