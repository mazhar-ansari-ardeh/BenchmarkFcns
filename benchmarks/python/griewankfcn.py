import numpy as np

def griewankfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Griewank benchmark function.

    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-N.

    Returns:
    --------
    np.ndarray: A vector SCORES of size M-by-1 in which each row contains the 
    function value for the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    sumcomp = np.zeros((x.shape[0], 1))
    prodcomp = np.ones((x.shape[0], 1))

    for i in range(n):
        sumcomp += x[:, i:i+1] ** 2
        prodcomp *= np.cos(x[:, i:i+1] / np.sqrt(i + 1))

    scores = (sumcomp / 4000) - prodcomp + 1
    return scores
