import numpy as np

def schwefel220fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel 2.20 function.

    Parameters:
    -----------
        x (np.ndarray): Input matrix of size M-by-N.

    Returns:
    --------
        np.ndarray: A vector of size M-by-1 in which each row contains the function
                    value for the corresponding row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.sum(np.abs(x), axis=1)
    return scores
