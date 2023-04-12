import numpy as np

def salomonfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Salomon's benchmark function.

    Args:
    x (ndarray): A matrix of size M-by-N.

    Returns:
    ndarray: A vector of size M-by-1 in which each row contains the function value for the corresponding row of X.

    For more information please visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    x2 = x ** 2
    sumx2 = np.sum(x2, axis=1)
    sqrtsx2 = np.sqrt(sumx2)

    scores = 1 - np.cos(2 * np.pi * sqrtsx2) + (0.1 * sqrtsx2)

    return scores
