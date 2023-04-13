import numpy as np

def xinsheyangn1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Xin-She Yang function at point x.
    
    Parameters
    ----------
    x : numpy.ndarray
        Input matrix of size M-by-N, where each row corresponds to the input for the function.
    
    Returns
    -------
    numpy.ndarray
        A vector of size M-by-1 in which each row contains the function value for the corresponding row of x.
    
    Reference
    ---------
    https://www.sfu.ca/~ssurjano/yangn1.html
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += np.random.rand() * np.abs(x[:, i])**i
    return scores
