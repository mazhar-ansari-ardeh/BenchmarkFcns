import numpy as np

def alpinen2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Alpine N. 2 function.

    Parameters:
    -----------
    x : numpy.ndarray
        Input array of shape (M, N) containing the points at which the function is evaluated.

    Returns:
    --------
    scores : numpy.ndarray
        A vector of size (M, 1) containing the function values for the corresponding row of x.

    See also: alpinen1fcn
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.

    """
    scores = np.prod(np.sqrt(x) * np.sin(x), axis=1)
    return scores
