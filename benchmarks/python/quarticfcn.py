import numpy as np

def quarticfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Quartic benchmark function.
    
    Parameters:
    -----------
    x (np.ndarray): Input matrix of size M-by-N.
    
    Returns:
    --------
    np.ndarray: Vector of size M-by-1 in which each row contains the function value for each row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service or 
    feel free to kindly modify the repository.
    """
    n = x.shape[1]
    
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += (i+1) * (x[:, i] ** 4)
    
    scores += np.random.rand()
    
    return scores
