import numpy as np

def schwefelfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel benchmark function.
    
    parameters:
    -----------
    x (numpy.ndarray): input matrix of size M-by-2
    
    Returns:
    --------
    numpy.ndarray: vetor of size M-by-1 in which each row contains the 
    function value for the corresponding row of X.
    
    The Schwefel function is defined as:
    f(x) = 418.9829*n - sum(x * sin(sqrt(abs(x))), 2)
    where n is the number of dimensions, and x is a 2D matrix where each row 
    corresponds to a set of n parameters.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = 418.9829 * n - np.sum(x * np.sin(np.sqrt(np.abs(x))), axis=1)
    return scores
