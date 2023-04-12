import numpy as np

def schaffern4fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schaffer N. 4 function at point x.

    Parameters:
    -----------
    x : numpy.ndarray
        Input matrix of size M-by-2, where M is the number of points to evaluate.

    Returns:
    --------
    scores : numpy.ndarray
        Vector of size M-by-1, where each row contains the function value for the corresponding row of x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    For more information please visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Schaffer function N. 4 is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    
    numeratorcomp = (np.cos(np.sin(np.abs(X ** 2 - Y ** 2))) ** 2) - 0.5
    denominatorcomp = (1 + 0.001 * (X ** 2 + Y ** 2)) ** 2
    scores = 0.5 + numeratorcomp / denominatorcomp
    
    return scores
