import numpy as np

def eggholderfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Eggholder benchmark function.

    Parameters:
    -----------
    x (numpy.ndarray): Input matrix of size M-by-2, where each row represents a 2D point.

    Returns:
    --------
    numpy.ndarray: Vector of size M-by-1, where each row contains the function value for the corresponding row of x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    The Eggholder function is only defined on a 2D space. For more information please visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service or feel free to kindly modify the repository.
    """

    assert x.shape[1] == 2, "The Eggholder function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    
    sin1component = np.sin(np.sqrt(np.abs((X / 2) + Y + 47)))
    sin2component = np.sin(np.sqrt(np.abs(X - Y + 47)))
    
    scores = -(Y + 47) * sin1component - (X * sin2component)
    return scores
