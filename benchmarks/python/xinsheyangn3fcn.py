import numpy as np

def xinsheyangn3fcn(x: np.ndarray, beta: float = 15, m: int = 5) -> np.ndarray:
    """
    Computes the value of the Xin-She Yang N. 3 function.

    The Xin-She Yang N. 3 function is a parametric function and it is
    behaviour can be controlled with two additional parameters 'beta' and
    'm'. In this implementation, the parameters are optional and when not
    given, their default value will be used.

    Parameters
    ----------
    x : numpy.ndarray
        Input array of shape (P, N).
    beta : float, optional
        Value for the 'beta' parameter of the function. Default is 15.
    m : int, optional
        Value for the 'm' parameter of the function. Default is 5.

    Returns
    -------
    scores : numpy.ndarray
        The output array of shape (P, 1) containing function values for each row of input x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.    
    """
    
    scores = np.exp(-np.sum((x / beta)**(2*m), axis=1)) - (2 * np.exp(-np.sum(x**2, axis=1)) * np.prod(np.cos(x)**2, axis=1))
    return scores
