import numpy as np

def zakharovfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Zakharov benchmark function.
    
    Parameters:
    -----------
    - x: numpy array of shape (M, N) where M is the number of points and N is the dimension of each point
    
    Returns:
    --------
    - scores: numpy array of shape (M, 1) where each row contains the function value for each row of x
    
    The Zakharov function is defined as: f(x) = sum(xi^2) + (sum(0.5*i*xi))^2 + (sum(0.5*i*xi))^4,
    where xi is the i-th component of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    comp1 = np.sum(x ** 2, axis=1)
    comp2 = np.sum(0.5 * np.arange(1, n+1) * x, axis=1)
    
    scores = comp1 + comp2 ** 2 + comp2 ** 4
    
    return scores
