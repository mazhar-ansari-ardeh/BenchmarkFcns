import numpy as np

def goldsteinpricefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Goldstein-Price benchmark function.
    
    Parameters
    ----------
    x : numpy.ndarray
        Input array of size M-by-2 where M is the number of points and 2 is the number of dimensions.
    
    Returns
    -------
    numpy.ndarray
        A 1D array of size M-by-1 containing the function value for each row of X.
    
    Raises
    ------
    AssertionError
        If the input array X is not of size M-by-2.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    assert x.shape[1] == 2, 'The Goldstein-Price function is only defined on a 2D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (1 + ((X + Y + 1)**2) * (19 - (14 * X) + (3 * (X **2)) - 14*Y + (6 * X * Y) + (3 * (Y**2)))) * \
        (30 + ((2 * X - 3 * Y)**2) * (18 - 32 * X + 12 * (X**2) + 48 * Y - (36 * X * Y) + (27 * (Y**2))) )
    
    return scores
