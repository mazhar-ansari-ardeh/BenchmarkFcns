import numpy as np

def birdfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Bird function.

    Parameters:
    -----------
    x (numpy.ndarray): A matrix of size M-by-2.

    Returns:
    --------
    numpy.ndarray: A vetor SCORES of size M-by-1 in which each row contains 
    the function value for the corresponding row of X.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'Bird function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]

    scores = np.sin(X) * np.exp((1 - np.cos(Y)) ** 2) + \
             np.cos(Y) * np.exp((1 - np.sin(X)) ** 2) + \
             (X - Y) ** 2

    return scores
