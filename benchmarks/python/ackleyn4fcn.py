import numpy as np

def ackleyn4fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Ackley N. 4 benchmark function.

    Parameters:
    x (numpy.ndarray): Input matrix of size M-by-N.

    Returns:
    scores (numpy.ndarray): Output vector of size M-by-1, in which each row contains the
    function value for each row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    m, n = x.shape

    scores = np.zeros((m, 1))

    for i in range(m):
        for j in range(n - 1):
            scores[i] = scores[i] + np.exp(-0.2) * np.sqrt(x[i, j]**2 + x[i, j+1]**2) \
                        + 3 * (np.cos(2 * x[i, j]) + np.sin(2 * x[i, j+1]))

    return scores
