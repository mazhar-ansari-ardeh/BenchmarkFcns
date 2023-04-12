import numpy as np

def shubert3fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Shubert 3 function.

    Parameters
    ----------
    x : numpy.ndarray
        Input matrix of size M-by-N.

    Returns
    -------
    numpy.ndarray
        Output vector of size M-by-1, where each row contains the 
        function value for the corresponding row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        for j in range(1, 6):
            scores += j * np.sin(((j + 1) * x[:, i]) + j)
    return scores
