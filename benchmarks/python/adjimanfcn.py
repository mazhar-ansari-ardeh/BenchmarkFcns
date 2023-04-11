import numpy as np

def adjimanfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Adjiman benchmark function.

    Args:
    x (np.ndarray): Matrix of size M-by-2.

    Returns:
    np.ndarray: Vector SCORES of size M-by-1, in which each row contains the function value 
    for the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    assert x.shape[1] == 2, 'Adjiman function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (np.cos(X) * np.sin(Y)) - (X / ((Y ** 2) + 1))
    
    return scores
