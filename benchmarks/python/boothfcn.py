import numpy as np

def boothfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Booth benchmark function.
    
    Parameters:
    -----------
    x : numpy.ndarray of shape (M, 2)
        The input matrix of size M-by-2, where each row represents a 2-dimensional point.
    
    Returns:
    --------
    scores : numpy.ndarray of shape (M, 1)
        The output vector of size M-by-1, where each row contains the function value
        for the corresponding row of x.
    
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, "Booth's function is only defined on a 2D space."
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (X + 2 * Y - 7)**2 + (2 * X + Y - 5)**2
    
    return scores
