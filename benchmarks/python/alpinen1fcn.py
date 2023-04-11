import numpy as np

def alpinen1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Alpine N. 1 function.

    Parameters:
    -----------
    x : np.ndarray
        A matrix of size M-by-N, where M is the number of points and N is the number of dimensions.

    Returns:
    --------
    np.ndarray
        A vector SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    scores = np.sum(np.abs(x * np.sin(x) + 0.1 * x), axis=1)
    return scores
