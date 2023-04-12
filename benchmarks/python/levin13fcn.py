import numpy as np

def levin13fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Lévi N. 13 benchmark function.

    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-2.

    Returns:
    --------
    np.ndarray: A vector SCORES of size M-by-1 in which each row contains the
    function value for the corresponding row of X.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, "Lévi's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    scores = np.sin(3 * np.pi * X) ** 2 + \
        ((X - 1) ** 2) * (1 + np.sin(3 * np.pi * Y) ** 2) + \
        ((Y - 1) ** 2) * (1 + np.sin(2 * np.pi * Y) ** 2)
    return scores
