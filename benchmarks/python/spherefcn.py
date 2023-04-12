import numpy as np

def spherefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Sphere benchmark function.
    
    Parameters:
    -----------
    - x (np.ndarray): Input matrix of size M-by-N.
    
    Returns:
    --------
    - np.ndarray: Vector of size M-by-1 containing the function value for each row of X.
    
    The function returns the sum of squared values for each row in the input matrix.
    For more information please visit: https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    f = np.sum(x**2, axis=1)
    return f.reshape(-1, 1)
