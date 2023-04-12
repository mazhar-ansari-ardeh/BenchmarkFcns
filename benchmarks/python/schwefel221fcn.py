import numpy as np

def schwefel221fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel 2.21 function.

    Parameters:
    -----------
    x (np.ndarray): Input matrix of size M-by-N.

    Returns:
    --------
    np.ndarray: Vector of size M-by-1 in which each row contains the
                function value for the corresponding row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.max(np.abs(x), axis=1)
    return scores
