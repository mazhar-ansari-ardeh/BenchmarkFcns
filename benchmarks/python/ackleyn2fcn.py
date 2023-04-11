import numpy as np

def ackleyn2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Ackley N. 2 function.

    Parameters
    ----------
    x : numpy.ndarray
        Input array of size M-by-2.

    Returns
    -------
    numpy.ndarray
        Output array of size M-by-1 in which each row contains the function
        value for the corresponding row of x.

    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    """
    n = x.shape[1]
    assert n == 2, 'Ackley N. 2 function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]

    scores = -200 * np.exp(-0.02 * np.sqrt(X**2 + Y**2))
    return scores
