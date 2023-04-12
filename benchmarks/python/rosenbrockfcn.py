import numpy as np

def rosenbrockfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Rosenbrock benchmark function.
    
    Parameters
    ----------
    x : numpy.ndarray of shape (M, N)
        The input matrix where each row is a sample of N-dimensional column vector.
    
    Returns
    -------
    numpy.ndarray of shape (M, 1)
        A vector containing the function value for each row of x.

    For more information please visit: 
    https://en.wikipedia.org/wiki/Rosenbrock_function

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.zeros((x.shape[0], 1))
    n = x.shape[1]
    assert n >= 1, 'Given input X cannot be empty'
    a = 1
    b = 100
    for i in range(n - 1):
        scores += b * ((x[:, i + 1] - (x[:, i] ** 2)) ** 2) + ((a - x[:, i]) ** 2)
    return scores
