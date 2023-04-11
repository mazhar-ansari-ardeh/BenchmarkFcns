import numpy as np

def bukinn6fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Bukin N. 6 benchmark function.
    
    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-2
    
    Returns:
    --------
    scores (np.ndarray): A vector SCORES of size M-by-1 in which each row contains the function value
      for the corresponding row of X.
      
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'The Bukin N. 6 functions is only defined on a 2D space.'
    
    X = x[:, 0]
    X2 = X ** 2
    Y = x[:, 1]
    
    scores = 100 * np.sqrt(np.abs(Y - 0.01 * X2)) + 0.01 * np.abs(X + 10)
    return scores
