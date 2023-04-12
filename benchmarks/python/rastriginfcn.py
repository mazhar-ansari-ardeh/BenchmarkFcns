import numpy as np

def rastriginfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Rastrigin benchmark function.

    Parameters
    ----------
    x : numpy.ndarray
        Input matrix of size M-by-N.

    Returns
    -------
    numpy.ndarray
        Output vector SCORES of size M-by-1.

    For more information, please visit:
    https://en.wikipedia.org/wiki/Rastrigin_function

    Author: Mazhar Ansari Ardeh

    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    A = 10
    f = (A * n) + np.sum(x ** 2 - A * np.cos(2 * np.pi * x), axis=1)
    return f.reshape(-1, 1)
