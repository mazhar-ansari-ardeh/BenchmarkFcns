import numpy as np

def brentfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Egg Crate function.
    
    Parameters:
    -----------
        x (np.ndarray): A matrix of size M-by-2.
        
    Returns:
    --------
        np.ndarray: A vector of size M-by-1 in which each row contains 
            the function value for the corresponding row of x.
            
    Computes the value of the Brent function at point x.
    The Brent function is defined only on the 2-D space.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'The Brent function is defined only on the 2-D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (X + 10)**2 + (Y + 10)**2 + np.exp(-X**2 - Y**2)
    return scores
