import numpy as np

def pichenyfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Picheny benchmark function.

    Parameters:
    -----------
    x (np.ndarray): Matrix of size M-by-2.

    Returns:
    --------
    np.ndarray: Vector SCORES of size M-by-1 in which each row contains 
    the function value for the corresponding row of X.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    For more information please visit:
    http://www.sfu.ca/~ssurjano/goldpr.html

    Note: The Picheny function is a modification of the Goldstein-Price function.
    See also: goldsteinpricefcn.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'The Picheny function is only defined on a 2D space.'
    X = 4 * x[:, 0] - 2
    Y = 4 * x[:, 1] - 2
    
    term = (1 + ((X + Y + 1)**2) * (19 - (14 * X) + (3 * (X**2)) - 14*Y + (6 * X*Y) + (3 * (Y**2)))) * \
        (30 + ((2 * X - 3 * Y)**2) * (18 - 32 * X + 12 * (X**2) + 48 * Y - (36 * X*Y) + (27 * (Y**2))))
    coef = 1 / 2.427
    scores = coef * (np.log10(term) - 8.693)
    return scores
