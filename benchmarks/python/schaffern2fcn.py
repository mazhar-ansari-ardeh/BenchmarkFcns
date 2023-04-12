import numpy as np

def schaffern2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schaffer N. 2 benchmark function.

    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-2 where each row contains the x and y values.

    Returns:
    --------
    np.ndarray: A vector SCORES of size M-by-1 in which each row contains the function value 
    for the corresponding row of X.

    For more information please visit: https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'The Schaffer N. 2 function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]

    sincomponent = np.sin((X ** 2) - (Y ** 2)) ** 2
    
    scores = 0.5 + ((sincomponent - 0.5) / (1 + 0.001 * (X ** 2 + Y ** 2)) ** 2)
    
    return scores
