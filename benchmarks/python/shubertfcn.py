import numpy as np

def shubertfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Shubert function.
    
    Parameters:
    -----------
    x: numpy.ndarray
        Input matrix of size M-by-N, where M is the number of points and N is the number of dimensions
    
    Returns:
    --------
    scores: numpy.ndarray
        Output vector of size M-by-1, where each row contains the function value for the corresponding row of x.
    
    See also: shubert3fcn, shubert4fcn
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service 
    or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.ones((x.shape[0], 1))
    
    for i in range(n):
        inner_sum = 0
        for j in range(1, 6):
            inner_sum += j * np.cos((j + 1) * x[:, i] + j)
        scores *= inner_sum.reshape(-1, 1)
    
    return scores
