import numpy as np

def periodicfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Sum Square function.
    
    Parameters:
    -----------
    x: A numpy array of shape (M, N) where M is the number of samples and N is the number of features.
    
    Returns:
    --------
    scores: A numpy array of shape (M, 1) containing the function value for each row of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    sin2x = np.sin(x) ** 2
    sumx2 = np.sum(x ** 2, axis=1)
    scores = 1 + np.sum(sin2x, axis=1) - 0.1 * np.exp(-sumx2)
    return scores
