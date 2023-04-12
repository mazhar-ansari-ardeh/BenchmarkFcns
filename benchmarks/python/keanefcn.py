import numpy as np

def keanefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Keane function at point X.

    Parameters
    ----------
    x : numpy.ndarray
        An array of shape (M, 2) containing M 2-dimensional points.

    Returns
    -------
    numpy.ndarray
        A 1-dimensional array of shape (M,) containing the function value for each
        point in `x`.

    Raises
    ------
    ValueError
        If the input array `x` is not of shape (M, 2).
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    if x.shape[1] != 2:
        raise ValueError("Keane function is defined only on a 2D space.")

    X = x[:, 0]
    Y = x[:, 1]
    numeratorcomp = (np.sin(X - Y) ** 2) * (np.sin(X + Y) ** 2)
    denominatorcomp = np.sqrt(X ** 2 + Y ** 2)
    scores = - numeratorcomp / denominatorcomp
    return scores
