import numpy as np

def wolfefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Wolfe function.

    Parameters:
    -----------
    x: numpy.ndarray
        A matrix of size M-by-3, where each row represents a point in 3D space.

    Returns:
    --------
    numpy.ndarray
        A vector SCORES of size M-by-1 in which each row contains the function
        value for the corresponding row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 3, 'The Wolfe function is defined only on the 3-D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    Z = x[:, 2]

    scores = (4/3)*(((X ** 2 + Y ** 2) - (X * Y))**(0.75)) + Z
    return scores
