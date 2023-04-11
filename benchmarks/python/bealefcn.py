import numpy as np

def bealefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Beale benchmark function.

    Parameters
    ----------
    x (ndarray): M-by-2 matrix of input points.

    Returns
    -------
    ndarray: M-by-1 vector of function values for each input point.

    The Beale function is only defined on a 2D space.
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Beale's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (1.5 - X + (X * Y))**2 + \
             (2.25 - X + (X * (Y**2)))**2 + \
             (2.625 - X + (X * (Y**3)))**2

    return scores
