import numpy as np

def dropwavefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Drop-Wave benchmark function.

    Parameters:
    -----------
    x : numpy.ndarray
        A matrix of size M-by-2 where each row represents a point in 2D space.

    Returns:
    --------
    scores : numpy.ndarray
        A vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'Drop-Wave function is only defined on a 2D space.'

    X = x[:, 0]
    Y = x[:, 1]

    numeratorcomp = 1 + np.cos(12 * np.sqrt(X ** 2 + Y ** 2))
    denumeratorcom = (0.5 * (X ** 2 + Y ** 2)) + 2

    scores = - numeratorcomp / denumeratorcom

    return scores
