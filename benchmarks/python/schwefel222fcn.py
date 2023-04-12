import numpy as np

def schwefel222fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel 2.22 function.
    
    Parameters:
    -----------
    x : numpy.ndarray
        Input array of size M-by-N.
        
    Returns:
    --------
    scores : numpy.ndarray
        Vector of size M-by-1 in which each row contains the function value
        for the corresponding row of x.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    absx = np.abs(x)
    scores = np.sum(absx, axis=1) + np.prod(absx, axis=1)
    return scores
