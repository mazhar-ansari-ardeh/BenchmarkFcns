import numpy as np

def exponentialfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Exponential function.
    
    Parameters:
    -----------
    x : np.ndarray
        Input matrix of size M-by-N.
    
    Returns:
    --------
    scores : np.ndarray
        Output vector of size M-by-1 containing the function value for each
        row of x.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    x2 = x ** 2
    scores = -np.exp(-0.5 * np.sum(x2, axis=1))
    return scores
