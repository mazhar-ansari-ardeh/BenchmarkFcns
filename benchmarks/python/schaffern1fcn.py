import numpy as np

def schaffern1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schaffer N. 1 function.

    Parameters
    ----------
    x : numpy.ndarray
        A matrix of size M-by-2.

    Returns
    -------
    numpy.ndarray
        A vector of size M-by-1 in which each row contains the 
        function value for the corresponding row of x.

    Raises
    ------
    ValueError
        If x is not a 2D matrix.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    if x.shape[1] != 2:
        raise ValueError('Schaffer function N. 1 is defined only on a 2D space.')
    X = x[:, 0]
    Y = x[:, 1]
    
    numeratorcomp = (np.sin((X ** 2 + Y ** 2) ** 2) ** 2) - 0.5
    denominatorcomp = (1 + 0.001 * (X ** 2 + Y ** 2)) ** 2
    scores = 0.5 + numeratorcomp / denominatorcomp
    
    return scores
