import numpy as np

def crossintrayfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Cross-in-tray benchmark function.
    
    Parameters:
    -----------
    x: np.ndarray
        An M-by-2 matrix where each row is a point at which the function is to be evaluated.
    
    Returns:
    --------
    scores: np.ndarray
        An M-by-1 vector in which each row contains the function value for the corresponding row of x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    For more information about the function, visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'The Cross-in-tray function is only defined on a 2D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    
    expcomponent = abs(100 - (np.sqrt(X ** 2 + Y ** 2) / np.pi))
    
    scores = -0.0001 * ((abs(np.sin(X) * np.sin(Y) * np.exp(expcomponent)) + 1) ** 0.1)
    
    return scores
