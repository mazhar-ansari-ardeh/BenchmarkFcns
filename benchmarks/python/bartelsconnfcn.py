import numpy as np

def bartelsconnfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Bartels Conn benchmark function.
    
    Parameters
    ----------
    x: A numpy array of shape (M, 2), where each row is a point in 2D space.
    
    Returns
    -------
    A numpy array of shape (M, 1) containing the function values for each corresponding point in x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'Bartels Conn function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = np.abs((X ** 2) + (Y ** 2) + (X * Y)) + np.abs(np.sin(X)) + np.abs(np.cos(Y))
    
    return scores
