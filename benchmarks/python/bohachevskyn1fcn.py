import numpy as np

def bohachevskyn1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Bohachevsky N. 1 benchmark function.
    
    Parameters:
    -----------
    x : np.ndarray of shape (M, 2)
        Input array with M rows and 2 columns representing the points
        at which the function value needs to be computed.
        
    Returns:
    --------
    scores : np.ndarray of shape (M, 1)
        A column vector in which each row contains the function value
        for each row of x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'The Bohachevsky N. 1 function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (X**2) + (2 * Y**2) - (0.3 * np.cos(3 * np.pi * X)) - (0.4 * np.cos(4 * np.pi * Y)) + 0.7
    
    return scores
