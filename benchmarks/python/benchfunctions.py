import numpy as np


def ackleyfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Ackley benchmark function.

    Parameters:
    x (numpy.ndarray): Input matrix of size M-by-N.

    Returns:
    numpy.ndarray: Vector SCORES of size M-by-1 in which each row contains the function value for each row of X.
    
    Ackley function is a benchmark function for optimization problems.
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    ninverse = 1 / n
    sum1 = np.sum(x ** 2, axis=1)
    sum2 = np.sum(np.cos(2 * np.pi * x), axis=1)

    scores = 20 + np.exp(1) - (20 * np.exp(-0.2 * np.sqrt(ninverse * sum1))) - np.exp(ninverse * sum2)
    return scores


def ackleyn2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Ackley N. 2 function.

    Parameters
    ----------
    x : numpy.ndarray
        Input array of size M-by-2.

    Returns
    -------
    numpy.ndarray
        Output array of size M-by-1 in which each row contains the function
        value for the corresponding row of x.

    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    """
    n = x.shape[1]
    assert n == 2, 'Ackley N. 2 function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]

    scores = -200 * np.exp(-0.02 * np.sqrt(X**2 + Y**2))
    return scores


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


def ackleyn4fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Ackley N. 4 benchmark function.

    Parameters:
    x (numpy.ndarray): Input matrix of size M-by-N.

    Returns:
    scores (numpy.ndarray): Output vector of size M-by-1, in which each row contains the
    function value for each row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    m, n = x.shape

    scores = np.zeros((m, 1))

    for i in range(m):
        for j in range(n - 1):
            scores[i] = scores[i] + np.exp(-0.2) * np.sqrt(x[i, j]**2 + x[i, j+1]**2) \
                        + 3 * (np.cos(2 * x[i, j]) + np.sin(2 * x[i, j+1]))

    return scores


def adjimanfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Adjiman benchmark function.

    Args:
    x (np.ndarray): Matrix of size M-by-2.

    Returns:
    np.ndarray: Vector SCORES of size M-by-1, in which each row contains the function value 
    for the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    assert x.shape[1] == 2, 'Adjiman function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (np.cos(X) * np.sin(Y)) - (X / ((Y ** 2) + 1))
    
    return scores


def alpinen1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Alpine N. 1 function.

    Parameters:
    -----------
    x : np.ndarray
        A matrix of size M-by-N, where M is the number of points and N is the number of dimensions.

    Returns:
    --------
    np.ndarray
        A vector SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    scores = np.sum(np.abs(x * np.sin(x) + 0.1 * x), axis=1)
    return scores


def alpinen2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Alpine N. 2 function.

    Parameters:
    -----------
    x : numpy.ndarray
        Input array of shape (M, N) containing the points at which the function is evaluated.

    Returns:
    --------
    scores : numpy.ndarray
        A vector of size (M, 1) containing the function values for the corresponding row of x.

    See also: alpinen1fcn
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.

    """
    scores = np.prod(np.sqrt(x) * np.sin(x), axis=1)
    return scores


def bartelsconnfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Bartels Conn benchmark function.
    
    Parameters
    ----------
    x: A numpy array of shape (M, 2), where each row is a point in 2D space.
    
    Returns
    -------
    A numpy array of shape (M, 1) containing the function values for each corresponding point in x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'Bartels Conn function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = np.abs((X ** 2) + (Y ** 2) + (X * Y)) + np.abs(np.sin(X)) + np.abs(np.cos(Y))
    
    return scores


def bealefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Beale benchmark function.

    Parameters
    ----------
    x (ndarray): M-by-2 matrix of input points.

    Returns
    -------
    ndarray: M-by-1 vector of function values for each input point.

    The Beale function is only defined on a 2D space.
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Beale's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (1.5 - X + (X * Y))**2 + \
             (2.25 - X + (X * (Y**2)))**2 + \
             (2.625 - X + (X * (Y**3)))**2

    return scores


def birdfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Bird function.

    Parameters:
    -----------
    x (numpy.ndarray): A matrix of size M-by-2.

    Returns:
    --------
    numpy.ndarray: A vetor SCORES of size M-by-1 in which each row contains 
    the function value for the corresponding row of X.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'Bird function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]

    scores = np.sin(X) * np.exp((1 - np.cos(Y)) ** 2) + \
             np.cos(Y) * np.exp((1 - np.sin(X)) ** 2) + \
             (X - Y) ** 2

    return scores


def bohachevskyn1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Bohachevsky N. 1 benchmark function.
    
    Parameters:
    -----------
    x : np.ndarray of shape (M, 2)
        Input array with M rows and 2 columns representing the points
        at which the function value needs to be computed.
        
    Returns:
    --------
    scores : np.ndarray of shape (M, 1)
        A column vector in which each row contains the function value
        for each row of x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'The Bohachevsky N. 1 function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (X**2) + (2 * Y**2) - (0.3 * np.cos(3 * np.pi * X)) - (0.4 * np.cos(4 * np.pi * Y)) + 0.7
    
    return scores


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


def boothfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Booth benchmark function.
    
    Parameters:
    -----------
    x : numpy.ndarray of shape (M, 2)
        The input matrix of size M-by-2, where each row represents a 2-dimensional point.
    
    Returns:
    --------
    scores : numpy.ndarray of shape (M, 1)
        The output vector of size M-by-1, where each row contains the function value
        for the corresponding row of x.
    
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, "Booth's function is only defined on a 2D space."
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (X + 2 * Y - 7)**2 + (2 * X + Y - 5)**2
    
    return scores


def brentfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Egg Crate function.
    
    Parameters:
    -----------
        x (np.ndarray): A matrix of size M-by-2.
        
    Returns:
    --------
        np.ndarray: A vector of size M-by-1 in which each row contains 
            the function value for the corresponding row of x.
            
    Computes the value of the Brent function at point x.
    The Brent function is defined only on the 2-D space.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'The Brent function is defined only on the 2-D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (X + 10)**2 + (Y + 10)**2 + np.exp(-X**2 - Y**2)
    return scores


def brownfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Brown benchmark function.

    Parameters:
    -----------
    x (ndarray): Input array of shape (M, N) where M is the number of points and N is the number of dimensions.

    Returns:
    --------
    ndarray: Array of size (M, 1) containing the function value for each corresponding row of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    x = x ** 2
    
    for i in range(n-1):
        scores += x[:, i] ** (x[:, i+1] + 1) + x[:, i+1] ** (x[:, i] + 1)
    
    return scores


def bukinn6fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Bukin N. 6 benchmark function.
    
    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-2
    
    Returns:
    --------
    scores (np.ndarray): A vector SCORES of size M-by-1 in which each row contains the function value
      for the corresponding row of X.
      
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'The Bukin N. 6 functions is only defined on a 2D space.'
    
    X = x[:, 0]
    X2 = X ** 2
    Y = x[:, 1]
    
    scores = 100 * np.sqrt(np.abs(Y - 0.01 * X2)) + 0.01 * np.abs(X + 10)
    return scores


def crossintrayfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Cross-in-tray benchmark function.
    
    Parameters:
    -----------
    x: np.ndarray
        An M-by-2 matrix where each row is a point at which the function is to be evaluated.
    
    Returns:
    --------
    scores: np.ndarray
        An M-by-1 vector in which each row contains the function value for the corresponding row of x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    For more information about the function, visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'The Cross-in-tray function is only defined on a 2D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    
    expcomponent = abs(100 - (np.sqrt(X ** 2 + Y ** 2) / np.pi))
    
    scores = -0.0001 * ((abs(np.sin(X) * np.sin(Y) * np.exp(expcomponent)) + 1) ** 0.1)
    
    return scores


def deckkersaartsfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Deckkers-Aarts function.

    Parameters:
    -----------
    x (ndarray): A matrix of size M-by-2.

    Returns:
    --------
    ndarray: A vector SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X.

    The Deckkers-Aarts function is defined as:
    f(x, y) = 100000*x^2 + y^2 - (x^2 + y^2)^2 + (10^-5) * (x^2 + y^2)^4

    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'The Deckkers-Aarts function is defined only on the 2-D space.'
    X = x[:, 0]
    Y = x[:, 1]

    scores = (100000 * X**2) + Y**2 - (X**2 + Y**2)**2 + (10**-5) * (X**2 + Y**2)**4

    return scores


def dropwavefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Drop-Wave benchmark function.

    Parameters:
    -----------
    x : numpy.ndarray
        A matrix of size M-by-2 where each row represents a point in 2D space.

    Returns:
    --------
    scores : numpy.ndarray
        A vetor SCORES of size M-by-1 in which each row contains the function value
        for the corresponding row of x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    assert n == 2, 'Drop-Wave function is only defined on a 2D space.'

    X = x[:, 0]
    Y = x[:, 1]

    numeratorcomp = 1 + np.cos(12 * np.sqrt(X ** 2 + Y ** 2))
    denumeratorcom = (0.5 * (X ** 2 + Y ** 2)) + 2

    scores = - numeratorcomp / denumeratorcom

    return scores


def easomfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Easom benchmark function.

    Parameters:
    -----------
    - x: An array of shape (M, 2), where each row represents a point in 2D space.

    Returns:
    --------
    - scores: An array of shape (M, 1) containing the function values corresponding to each point in x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    The Easom function is only defined on a 2D space. For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, "The Easom's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]

    scores = -np.cos(X) * np.cos(Y) * np.exp(-((X - np.pi) ** 2 + (Y - np.pi) ** 2))
    return scores


def eggcratefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Egg Crate function.
    
    Parameters:
    -----------
    x (numpy.ndarray): A matrix of size M-by-2.
    
    Returns:
    --------
    numpy.ndarray: A vetor SCORES of size M-by-1 in which each row contains 
                   the function value for the corresponding row of X.           
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'The Egg Crate function is defined only on the 2-D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = X**2 + Y**2 + (25 * (np.sin(X)**2 + np.sin(Y)**2))
    return scores


def eggholderfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Eggholder benchmark function.

    Parameters:
    -----------
    x (numpy.ndarray): Input matrix of size M-by-2, where each row represents a 2D point.

    Returns:
    --------
    numpy.ndarray: Vector of size M-by-1, where each row contains the function value for the corresponding row of x.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    The Eggholder function is only defined on a 2D space. For more information please visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service or feel free to kindly modify the repository.
    """

    assert x.shape[1] == 2, "The Eggholder function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    
    sin1component = np.sin(np.sqrt(np.abs((X / 2) + Y + 47)))
    sin2component = np.sin(np.sqrt(np.abs(X - Y + 47)))
    
    scores = -(Y + 47) * sin1component - (X * sin2component)
    return scores


def exponentialfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Exponential function.
    
    Parameters:
    -----------
    x : np.ndarray
        Input matrix of size M-by-N.
    
    Returns:
    --------
    scores : np.ndarray
        Output vector of size M-by-1 containing the function value for each
        row of x.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    x2 = x ** 2
    scores = -np.exp(-0.5 * np.sum(x2, axis=1))
    return scores


def goldsteinpricefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Goldstein-Price benchmark function.
    
    Parameters
    ----------
    x : numpy.ndarray
        Input array of size M-by-2 where M is the number of points and 2 is the number of dimensions.
    
    Returns
    -------
    numpy.ndarray
        A 1D array of size M-by-1 containing the function value for each row of X.
    
    Raises
    ------
    AssertionError
        If the input array X is not of size M-by-2.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    assert x.shape[1] == 2, 'The Goldstein-Price function is only defined on a 2D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (1 + ((X + Y + 1)**2) * (19 - (14 * X) + (3 * (X **2)) - 14*Y + (6 * X * Y) + (3 * (Y**2)))) * \
        (30 + ((2 * X - 3 * Y)**2) * (18 - 32 * X + 12 * (X**2) + 48 * Y - (36 * X * Y) + (27 * (Y**2))) )
    
    return scores


def gramacyleefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Gramacy & Lee benchmark function.

    Parameters:
    -----------
    x : numpy.ndarray of shape (M, 1)
        The input points at which the function values are computed.
    Returns:
    --------
    scores : numpy.ndarray of shape (M, 1)
        The function values at the corresponding input points.
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 1, 'Gramacy & Lee function is only defined on a 1-D space.'

    scores = (np.sin(10 * np.pi * x) / (2 * x)) + ((x - 1) ** 4)
    return scores


def griewankfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Griewank benchmark function.

    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-N.

    Returns:
    --------
    np.ndarray: A vector SCORES of size M-by-1 in which each row contains the 
    function value for the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    sumcomp = np.zeros((x.shape[0], 1))
    prodcomp = np.ones((x.shape[0], 1))

    for i in range(n):
        sumcomp += x[:, i:i+1] ** 2
        prodcomp *= np.cos(x[:, i:i+1] / np.sqrt(i + 1))

    scores = (sumcomp / 4000) - prodcomp + 1
    return scores


def happycatfcn(x: np.ndarray, alpha: float = 0.5) -> np.ndarray:
    """
    Computes the value of the Happy Cat benchmark function.
    
    Parameters:
    -----------
    - x: A matrix of size M-by-N.
    - alpha: Power of the sphere component of the function (default: 0.5).
    
    Returns:
    --------
    - scores: A vector of size M-by-1 in which each row contains the function value for 
    the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    x2 = np.sum(x * x, axis=1)
    scores = ((x2 - n)**2)**alpha + (0.5*x2 + np.sum(x,axis=1))/n + 0.5
    return scores


def himmelblaufcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Himmelblau's benchmark function.

    Parameters:
    -----------
        x (ndarray): A matrix of size M-by-2.

    Returns:
    --------
        ndarray: A vetor SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    Himmelblau's function is defined as:
        f(x,y) = (x^2 + y - 11)^2 + (x + y^2 - 7)^2

    For more information please visit: 
    https://en.wikipedia.org/wiki/Himmelblau's_function

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Himmelblau's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    scores = ((X ** 2 + Y - 11) ** 2) + ((X + Y ** 2 - 7) ** 2)
    return scores


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


def leonfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Leon function.

    Parameters:
    -----------
    x: An array of shape (M, 2) where M is the number of data points.
       Each row represents a data point in 2-dimensional space.

    Returns:
    --------
    scores: A 1-dimensional array of length M containing the function value
            for each corresponding row of x.

    Raises
    ------
    AssertionError 
        If the input array x is not of shape (M, 2).
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    assert x.shape[1] == 2, 'Leon function is defined only on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    scores = 100 * ((Y - X**3) ** 2) + ((1 - X) ** 2)
    return scores


def levin13fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Lévi N. 13 benchmark function.

    Parameters:
    -----------
    x (np.ndarray): A matrix of size M-by-2.

    Returns:
    --------
    np.ndarray: A vector SCORES of size M-by-1 in which each row contains the
    function value for the corresponding row of X.
    
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, "Lévi's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    scores = np.sin(3 * np.pi * X) ** 2 + \
        ((X - 1) ** 2) * (1 + np.sin(3 * np.pi * Y) ** 2) + \
        ((Y - 1) ** 2) * (1 + np.sin(2 * np.pi * Y) ** 2)
    return scores


def matyasfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Matyas benchmark function.

    Args:
        x (numpy.ndarray): Input matrix of size M-by-2.

    Returns:
    --------
        numpy.ndarray: Vector of size M-by-1 in which each row contains the
        function value for the corresponding row of X.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    The Matyas function is only defined on a 2D space. For more information,
    please visit: https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Matyas's function is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]

    scores = 0.26 * (X ** 2 + Y ** 2) - 0.48 * X * Y
    return scores


def mccormickfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the McCormick benchmark function.
    
    Parameters:
    -----------
    x : numpy.ndarray of shape (M, 2)
        Input matrix where each row is a point in 2D space.
        
    Returns:
    --------
    scores : numpy.ndarray of shape (M, 1)
        Vector of function values for each input point in x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    More information: https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    assert n == 2, 'The McCormick function is only defined on a 2D space.'
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = np.sin(X + Y) + ((X - Y) ** 2 ) - 1.5 * X + 2.5 * Y + 1
    return scores


def periodicfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Sum Square function.
    
    Parameters:
    -----------
    x: A numpy array of shape (M, N) where M is the number of samples and N is the number of features.
    
    Returns:
    --------
    scores: A numpy array of shape (M, 1) containing the function value for each row of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    sin2x = np.sin(x) ** 2
    sumx2 = np.sum(x ** 2, axis=1)
    scores = 1 + np.sum(sin2x, axis=1) - 0.1 * np.exp(-sumx2)
    return scores


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


def powellsumfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Powell Sum benchmark function.

    Parameters
    ----------
    x : numpy.ndarray
        Input array of size M-by-N.

    Returns
    -------
    numpy.ndarray
        Array of function values for each row of x. The shape of the array is M-by-1.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    absx = np.abs(x)

    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += absx[:, i] ** (i + 1)

    return scores


def qingfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Qing function at point X.

    Parameters:
    -----------
        x (numpy.ndarray): Matrix of size M-by-N.
    
    Returns:
    --------
        numpy.ndarray: Vector of size M-by-1 in which each row contains the 
                       function value for the corresponding row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    x2 = x ** 2

    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += (x2[:, i] - (i+1)) ** 2

    return scores


def quarticfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Quartic benchmark function.
    
    Parameters:
    -----------
    x (np.ndarray): Input matrix of size M-by-N.
    
    Returns:
    --------
    np.ndarray: Vector of size M-by-1 in which each row contains the function value for each row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at Google's e-mail service or 
    feel free to kindly modify the repository.
    """
    n = x.shape[1]
    
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += (i+1) * (x[:, i] ** 4)
    
    scores += np.random.rand()
    
    return scores


def rastriginfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Rastrigin benchmark function.

    Parameters
    ----------
    x : numpy.ndarray
        Input matrix of size M-by-N.

    Returns
    -------
    numpy.ndarray
        Output vector SCORES of size M-by-1.

    For more information, please visit:
    https://en.wikipedia.org/wiki/Rastrigin_function

    Author: Mazhar Ansari Ardeh

    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """

    n = x.shape[1]
    A = 10
    f = (A * n) + np.sum(x ** 2 - A * np.cos(2 * np.pi * x), axis=1)
    return f.reshape(-1, 1)


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


def rosenbrockfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Rosenbrock benchmark function.
    
    Parameters
    ----------
    x : numpy.ndarray of shape (M, N)
        The input matrix where each row is a sample of N-dimensional column vector.
    
    Returns
    -------
    numpy.ndarray of shape (M, 1)
        A vector containing the function value for each row of x.

    For more information please visit: 
    https://en.wikipedia.org/wiki/Rosenbrock_function

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.zeros((x.shape[0], 1))
    n = x.shape[1]
    assert n >= 1, 'Given input X cannot be empty'
    a = 1
    b = 100
    for i in range(n - 1):
        scores += b * ((x[:, i + 1] - (x[:, i] ** 2)) ** 2) + ((a - x[:, i]) ** 2)
    return scores


def salomonfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Salomon's benchmark function.

    Parameters:
    -----------
    x (ndarray): A matrix of size M-by-N.

    Returns:
    --------
    ndarray: A vector of size M-by-1 in which each row contains the function value for the corresponding row of X.

    For more information please visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    x2 = x ** 2
    sumx2 = np.sum(x2, axis=1)
    sqrtsx2 = np.sqrt(sumx2)

    scores = 1 - np.cos(2 * np.pi * sqrtsx2) + (0.1 * sqrtsx2)

    return scores


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


def schaffern3fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schaffer N. 3 function.
    
    Parameters:
    -----------
    x: numpy.ndarray
        A matrix of size M-by-2.
    
    Returns:
    --------
    scores: numpy.ndarray
        A vetor of size M-by-1 in which each row contains the 
        function value for the corresponding row of X.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.
    
    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, 'Schaffer function N. 3 is only defined on a 2D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    
    numeratorcomp = (np.sin(np.cos(np.abs(X ** 2 - Y ** 2))) ** 2) - 0.5
    denominatorcomp = (1 + 0.001 * (X ** 2 + Y ** 2)) ** 2
    scores = 0.5 + numeratorcomp / denominatorcomp
    
    return scores


def schaffern4fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schaffer N. 4 function at point x.

    Parameters:
    -----------
    x : numpy.ndarray
        Input matrix of size M-by-2, where M is the number of points to evaluate.

    Returns:
    --------
    scores : numpy.ndarray
        Vector of size M-by-1, where each row contains the function value for the corresponding row of x.
        
    Raises
    ------
    AssertionError
        If the input array has a number of columns different from 2.

    For more information please visit:
    https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 2, "Schaffer function N. 4 is only defined on a 2D space."
    X = x[:, 0]
    Y = x[:, 1]
    
    numeratorcomp = (np.cos(np.sin(np.abs(X ** 2 - Y ** 2))) ** 2) - 0.5
    denominatorcomp = (1 + 0.001 * (X ** 2 + Y ** 2)) ** 2
    scores = 0.5 + numeratorcomp / denominatorcomp
    
    return scores


def schwefel220fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel 2.20 function.

    Parameters:
    -----------
        x (np.ndarray): Input matrix of size M-by-N.

    Returns:
    --------
        np.ndarray: A vector of size M-by-1 in which each row contains the function
                    value for the corresponding row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.sum(np.abs(x), axis=1)
    return scores


def schwefel221fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel 2.21 function.

    Parameters:
    -----------
    x (np.ndarray): Input matrix of size M-by-N.

    Returns:
    --------
    np.ndarray: Vector of size M-by-1 in which each row contains the
                function value for the corresponding row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.max(np.abs(x), axis=1)
    return scores


def schwefel222fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel 2.22 function.
    
    Parameters:
    -----------
    x : numpy.ndarray
        Input array of size M-by-N.
        
    Returns:
    --------
    scores : numpy.ndarray
        Vector of size M-by-1 in which each row contains the function value
        for the corresponding row of x.
        
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    absx = np.abs(x)
    scores = np.sum(absx, axis=1) + np.prod(absx, axis=1)
    return scores


def schwefelfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Schwefel benchmark function.
    
    parameters:
    -----------
    x (numpy.ndarray): input matrix of size M-by-2
    
    Returns:
    --------
    numpy.ndarray: vetor of size M-by-1 in which each row contains the 
    function value for the corresponding row of X.
    
    The Schwefel function is defined as:
    f(x) = 418.9829*n - sum(x * sin(sqrt(abs(x))), 2)
    where n is the number of dimensions, and x is a 2D matrix where each row 
    corresponds to a set of n parameters.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = 418.9829 * n - np.sum(x * np.sin(np.sqrt(np.abs(x))), axis=1)
    return scores


def shubert3fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Shubert 3 function.

    Parameters
    ----------
    x : numpy.ndarray
        Input matrix of size M-by-N.

    Returns
    -------
    numpy.ndarray
        Output vector of size M-by-1, where each row contains the 
        function value for the corresponding row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        for j in range(1, 6):
            scores += j * np.sin(((j + 1) * x[:, i]) + j)
    return scores


def shubert4fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Shubert 4 function.

    Parameters:
    -----------
        x (np.ndarray): A matrix of size M-by-N.

    Returns:
    --------
        np.ndarray: A vector of size M-by-1 in which each row contains the
        function value for the corresponding row of x.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        for j in range(5):
            scores += np.cos(((j + 1) * x[:, i]) + j)
    
    return scores


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


def spherefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Sphere benchmark function.
    
    Parameters:
    -----------
    - x (np.ndarray): Input matrix of size M-by-N.
    
    Returns:
    --------
    - np.ndarray: Vector of size M-by-1 containing the function value for each row of X.
    
    The function returns the sum of squared values for each row in the input matrix.
    For more information please visit: https://en.wikipedia.org/wiki/Test_functions_for_optimization
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    f = np.sum(x**2, axis=1)
    return f.reshape(-1, 1)


def styblinskitankfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Styblinski-Tank benchmark function.

    Parameters:
    -----------
    x : np.ndarray
        A matrix of size M-by-2 representing the input points.

    Returns:
    --------
    scores : np.ndarray
        A vector of size M-by-1 in which each row contains the function value 
        for the corresponding row of X.

    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += x[:, i]**4 - 16*x[:, i]**2 + 5*x[:, i]
    scores *= 0.5
    return scores


def sumsquaresfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Sum Squares function.

    Parameters:
    -----------
    x (ndarray): Matrix of size M-by-N.

    Returns:
    --------
    ndarray: Vector of size M-by-1 in which each row contains the function value for the corresponding row of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    m, n = x.shape
    x2 = x ** 2
    I = np.tile(np.arange(1, n+1), (m, 1))
    scores = np.sum(I * x2, axis=1, keepdims=True)

    return scores


def threehumpcamelfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Three-hump camel benchmark function.

    Parameters
    ----------
    x : numpy.ndarray
        A matrix of size M-by-2.

    Returns
    -------
    numpy.ndarray
        A vetor SCORES of size M-by-1 in which each row contains the 
        function value for the corresponding row of X.

    Raises
    ------
    ValueError
        If the input matrix x is not of size M-by-2.

    For more information please visit: 
    https://en.wikipedia.org/wiki/Test_functions_for_optimization

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    if x.shape[1] != 2:
        raise ValueError('The Three-hump camel function is only defined on a 2D space.')
    
    X = x[:, 0]
    Y = x[:, 1]
    
    scores = (2 * X**2) - (1.05 * (X**4)) + ((X**6) / 6) + X * Y + Y**2
    
    return scores


def wolfefcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Wolfe function.

    Parameters:
    -----------
    x: numpy.ndarray
        A matrix of size M-by-3, where each row represents a point in 3D space.

    Returns:
    --------
    numpy.ndarray
        A vector SCORES of size M-by-1 in which each row contains the function
        value for the corresponding row of X.

    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    assert n == 3, 'The Wolfe function is defined only on the 3-D space.'
    
    X = x[:, 0]
    Y = x[:, 1]
    Z = x[:, 2]

    scores = (4/3)*(((X ** 2 + Y ** 2) - (X * Y))**(0.75)) + Z
    return scores


def xinsheyangn1fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Xin-She Yang function at point x.
    
    Parameters
    ----------
    x : numpy.ndarray
        Input matrix of size M-by-N, where each row corresponds to the input for the function.
    
    Returns
    -------
    numpy.ndarray
        A vector of size M-by-1 in which each row contains the function value for the corresponding row of x.
    
    Reference
    ---------
    https://www.sfu.ca/~ssurjano/yangn1.html
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    n = x.shape[1]
    scores = np.zeros((x.shape[0], 1))
    for i in range(n):
        scores += np.random.rand() * np.abs(x[:, i])**i
    return scores


def xinsheyangn2fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Xin-She Yang N. 2 function.
    
    Parameters:
    -----------
    x (numpy.ndarray): input matrix of size M-by-N
    
    Returns:
    --------
    numpy.ndarray: vetor SCORES of size M-by-1 in which each row contains the function value for the corresponding row of X
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = np.sum(np.abs(x), axis=1) * np.exp(-np.sum(np.sin(x ** 2), axis=1))
    return scores


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


def xinsheyangn4fcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of the Xin-She Yang N. 4 function.
    
    Parameters:
    -----------
    x (numpy.ndarray): input matrix of size M-by-N
    
    Returns:
    --------
    numpy.ndarray: A vector of size M-by-1 in which each row contains the 
                    function value for the corresponding row of X.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    scores = (np.sum(np.sin(x) ** 2, axis=1) - np.exp(-np.sum(x ** 2, axis=1))) * np.exp(-np.sum(np.sin(np.sqrt(np.abs(x))) ** 2, axis=1))
    return scores


def zakharovfcn(x: np.ndarray) -> np.ndarray:
    """
    Computes the value of Zakharov benchmark function.
    
    Parameters:
    -----------
    - x: numpy array of shape (M, N) where M is the number of points and N is the dimension of each point
    
    Returns:
    --------
    - scores: numpy array of shape (M, 1) where each row contains the function value for each row of x
    
    The Zakharov function is defined as: f(x) = sum(xi^2) + (sum(0.5*i*xi))^2 + (sum(0.5*i*xi))^4,
    where xi is the i-th component of x.
    
    Author: Mazhar Ansari Ardeh
    Please forward any comments or bug reports to mazhar.ansari.ardeh at
    Google's e-mail service or feel free to kindly modify the repository.
    """
    
    n = x.shape[1]
    comp1 = np.sum(x ** 2, axis=1)
    comp2 = np.sum(0.5 * np.arange(1, n+1) * x, axis=1)
    
    scores = comp1 + comp2 ** 2 + comp2 ** 4
    
    return scores
