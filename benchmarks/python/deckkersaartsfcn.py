import numpy as np

def deckkersaartsfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Deckkers-Aarts function.

    Parameters:
    -----------
    x (ndarray): A matrix of size M-by-2.

    Returns:
    --------
    ndarray: A vector SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X.

    The Deckkers-Aarts function is defined as:
    f(x, y) = 100000*x^2 + y^2 - (x^2 + y^2)^2 + (10^-5) * (x^2 + y^2)^4

    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'The Deckkers-Aarts function is defined only on the 2-D space.'
    X = x[:, 0]
    Y = x[:, 1]

    scores = (100000 * X**2) + Y**2 - (X**2 + Y**2)**2 + (10**-5) * (X**2 + Y**2)**4

    return scores
