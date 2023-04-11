import numpy as np

def bohachevskyn2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Bohachevsky N. 2 benchmark function.

    Parameters
    ----------
    x : numpy.ndarray of shape (M, 2)
        Input matrix of M 2-dimensional points.

    Returns
    -------
    scores : numpy.ndarray of shape (M,)
        Vector of function values for each point in `x`.

    Raises
    ------
    ValueError
        If the input `x` does not have 2 columns.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.

    """
    if x.shape[1] != 2:
        raise ValueError('The Bohachevsky N. 2 function is only defined on a 2D space.')
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = X**2 + 2*Y**2 - 0.3*np.cos(3*np.pi*X)*np.cos(4*np.pi*Y) + 0.3
    
    return scores
