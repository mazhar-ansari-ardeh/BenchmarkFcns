import numpy as np

def happycatfcn(x: np.ndarray, alpha: float = 0.5) -> np.ndarray:
    """
    Computes the value of the Happy Cat benchmark function.
    
    Parameters:
    -----------
    - x: A matrix of size M-by-N.
    - alpha: Power of the sphere component of the function (default: 0.5).
    
    Returns:
    --------
    - scores: A vector of size M-by-1 in which each row contains the function value for 
    the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    x2 = np.sum(x * x, axis=1)
    scores = ((x2 - n)**2)**alpha + (0.5*x2 + np.sum(x,axis=1))/n + 0.5
    return scores
