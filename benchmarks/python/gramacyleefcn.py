import numpy as np

def gramacyleefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Gramacy & Lee benchmark function.

    Parameters:
    -----------
    x : numpy.ndarray of shape (M, 1)
        The input points at which the function values are computed.
    Returns:
    --------
    scores : numpy.ndarray of shape (M, 1)
        The function values at the corresponding input points.
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 1, 'Gramacy & Lee function is only defined on a 1-D space.'

    scores = (np.sin(10 * np.pi * x) / (2 * x)) + ((x - 1) ** 4)
    return scores
