import numpy as np

def styblinskitankfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Styblinski-Tank benchmark function.

    Parameters:
    -----------
    x : np.ndarray
        A matrix of size M-by-2 representing the input points.

    Returns:
    --------
    scores : np.ndarray
        A vector of size M-by-1 in which each row contains the function value 
        for the corresponding row of X.

    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += x[:, i]**4 - 16*x[:, i]**2 + 5*x[:, i]
    scores *= 0.5
    return scores
