import numpy as np

def holdertablefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Holder table benchmark function.
    
    Parameters
    ----------
    x : numpy.ndarray of shape (M, 2)
        Input matrix where each row represents a point in a 2D space.
    
    Returns
    -------
    scores : numpy.ndarray of shape (M, 1)
        A vector containing the function values for each corresponding row of x.
    
    Raises
    ------
    ValueError
        If the input matrix is not of size M-by-2.
    
    References
    ----------
    [1] https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    if x.shape[1] != 2:
        raise ValueError('The Holder table function is only defined on a 2D space.')
    
    X = x[:, 0]
    Y = x[:, 1]
    
    expcomponent = np.exp(np.abs(1 - (np.sqrt(X ** 2 + Y ** 2) / np.pi)))
    
    scores = -np.abs(np.sin(X) * np.cos(Y) * expcomponent)
    
    return scores
