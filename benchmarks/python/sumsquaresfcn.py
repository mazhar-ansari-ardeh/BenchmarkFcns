import numpy as np

def sumsquaresfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Sum Squares function.

    Parameters:
    -----------
    x (ndarray): Matrix of size M-by-N.

    Returns:
    --------
    ndarray: Vector of size M-by-1 in which each row contains the function value for the corresponding row of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    m, n = x.shape
    x2 = x ** 2
    I = np.tile(np.arange(1, n+1), (m, 1))
    scores = np.sum(I * x2, axis=1, keepdims=True)

    return scores
