import numpy as np

def leonfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Leon function.

    Parameters:
    -----------
    x: An array of shape (M, 2) where M is the number of data points.
       Each row represents a data point in 2-dimensional space.

    Returns:
    --------
    scores: A 1-dimensional array of length M containing the function value
            for each corresponding row of x.

    Raises
    ------
    AssertionError 
        If the input array x is not of shape (M, 2).
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    assert x.shape[1] == 2, 'Leon function is defined only on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    scores = 100 * ((Y - X**3) ** 2) + ((1 - X) ** 2)
    return scores
