import numpy as np

def himmelblaufcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Himmelblau's benchmark function.

    Parameters:
    -----------
        x (ndarray): A matrix of size M-by-2.

    Returns:
    --------
        ndarray: A vetor SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    Himmelblau's function is defined as:
        f(x,y) = (x^2 + y - 11)^2 + (x + y^2 - 7)^2

    For more information please visit: 
    https://en.wikipedia.org/wiki/Himmelblau's_function

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Himmelblau's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    scores = ((X ** 2 + Y - 11) ** 2) + ((X + Y ** 2 - 7) ** 2)
    return scores
