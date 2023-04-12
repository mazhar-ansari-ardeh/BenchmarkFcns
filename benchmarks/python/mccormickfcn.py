import numpy as np

def mccormickfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the McCormick benchmark function.
    
    Parameters:
    -----------
    x : numpy.ndarray of shape (M, 2)
        Input matrix where each row is a point in 2D space.
        
    Returns:
    --------
    scores : numpy.ndarray of shape (M, 1)
        Vector of function values for each input point in x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    More information: https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'The McCormick function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = np.sin(X + Y) + ((X - Y) ** 2 ) - 1.5 * X + 2.5 * Y + 1
    return scores
