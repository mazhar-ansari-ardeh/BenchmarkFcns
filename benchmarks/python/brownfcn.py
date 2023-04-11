import numpy as np

def brownfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Brown benchmark function.

    Parameters:
    -----------
    x (ndarray): Input array of shape (M, N) where M is the number of points and N is the number of dimensions.

    Returns:
    --------
    ndarray: Array of size (M, 1) containing the function value for each corresponding row of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    x = x ** 2
    
    for i in range(n-1):
        scores += x[:, i] ** (x[:, i+1] + 1) + x[:, i+1] ** (x[:, i] + 1)
    
    return scores
