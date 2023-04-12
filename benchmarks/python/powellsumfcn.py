import numpy as np

def powellsumfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Powell Sum benchmark function.

    Parameters
    ----------
    x : numpy.ndarray
        Input array of size M-by-N.

    Returns
    -------
    numpy.ndarray
        Array of function values for each row of x. The shape of the array is M-by-1.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    absx = np.abs(x)

    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += absx[:, i] ** (i + 1)

    return scores
