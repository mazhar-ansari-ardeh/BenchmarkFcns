import numpy as np

def threehumpcamelfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Three-hump camel benchmark function.

    Parameters
    ----------
    x : numpy.ndarray
        A matrix of size M-by-2.

    Returns
    -------
    numpy.ndarray
        A vetor SCORES of size M-by-1 in which each row contains the 
        function value for the corresponding row of X.

    Raises
    ------
    ValueError
        If the input matrix x is not of size M-by-2.

    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    if x.shape[1] != 2:
        raise ValueError('The Three-hump camel function is only defined on a 2D space.')
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (2 * X**2) - (1.05 * (X**4)) + ((X**6) / 6) + X * Y + Y**2
    
    return scores
