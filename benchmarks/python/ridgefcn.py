import numpy as np

def ridgefcn(x: np.ndarray, d: float = 1, alpha: float = 0.5) -> np.ndarray:
    """
    Computes the value of the Ridge benchmark function.

    Parameters:
    -----------
    x: np.ndarray, shape=(M, N)
        Matrix of size M-by-N containing the input points.
    d: float, optional (default=1)
        Contribution coefficient of the sphere component of the function.
    alpha: float, optional (default=0.5)
        Power of the sphere component of the function.

    Returns:
    --------
    scores: np.ndarray, shape=(M, 1)
        Vector of size M-by-1 containing the function value for each row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    x1 = x[:, 0]
    scores = x1 + d * (np.sum(x[:, 1:]**2, axis=1) ** alpha)
    return scores
