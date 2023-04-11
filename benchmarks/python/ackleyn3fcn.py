import numpy as np

def ackleyn3fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Ackley N. 3 function for the input 2D array x.
    
    Args:
    x: Input array of shape (n_samples, 2).
    
    Returns:
    scores: Array of shape (n_samples,) containing the function scores for each sample in x.
    """
    n = x.shape[1]
    assert n == 2, 'Ackley N. 3 function is only defined on a 2D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = -200 * np.exp(-0.2 * np.sqrt(X**2 + Y**2)) + 5 * np.exp(np.cos(3*X) + np.sin(3*Y))
    
    return scores
