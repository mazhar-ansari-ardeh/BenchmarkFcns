import numpy as np

def ackleyfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Ackley benchmark function.

    Parameters:
    x (numpy.ndarray): Input matrix of size M-by-N.

    Returns:
    numpy.ndarray: Vector SCORES of size M-by-1 in which each row contains the function value for each row of X.
    
    Ackley function is a benchmark function for optimization problems.
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    ninverse = 1 / n
    sum1 = np.sum(x ** 2, axis=1)
    sum2 = np.sum(np.cos(2 * np.pi * x), axis=1)

    scores = 20 + np.exp(1) - (20 * np.exp(-0.2 * np.sqrt(ninverse * sum1))) - np.exp(ninverse * sum2)
    return scores
