import numpy as np

def easomfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Easom benchmark function.

    Parameters:
    -----------
    - x: An array of shape (M, 2), where each row represents a point in 2D space.

    Returns:
    --------
    - scores: An array of shape (M, 1) containing the function values corresponding to each point in x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    The Easom function is only defined on a 2D space. For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, "The Easom's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]

    scores = -np.cos(X) * np.cos(Y) * np.exp(-((X - np.pi) ** 2 + (Y - np.pi) ** 2))
    return scores
