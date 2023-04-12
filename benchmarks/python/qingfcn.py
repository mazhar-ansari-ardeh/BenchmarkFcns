import numpy as np

def qingfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Qing function at point X.

    Parameters:
    -----------
        x (numpy.ndarray): Matrix of size M-by-N.
    
    Returns:
    --------
        numpy.ndarray: Vector of size M-by-1 in which each row contains the 
                       function value for the corresponding row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    x2 = x ** 2

    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += (x2[:, i] - (i+1)) ** 2

    return scores
