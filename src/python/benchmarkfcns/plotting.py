from __future__ import annotations

import numpy as np


def meshgrid(
    x: np.ndarray | list, y: np.ndarray | list, fcn: callable
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    """
    Create a meshgrid of points for a given function. The function is evaluated at each
    point of the grid and the resulting function values are returned. To evaluate the
    points of the grid, the function is vectorised and the function values are calculated
    in a single function call, instead of calculating the function value for each point.

    Parameters:
    -----------
    x : np.ndarray or list
        1D array of x values.
    y : np.ndarray or list
        1D array of y values.
    fcn : callable
        Function to evaluate at each point of the grid. The function should accept a
        2D array of points as input and return a 1D array of function values.
    Returns:
    --------
    X : np.ndarray
        2D array of x values, represeting the x-coordinates of the grid points.
    Y : np.ndarray
        2D array of y values, represeting the y-coordinates of the grid points.
    Z : np.ndarray
        2D array of function values obtained from `fcn` for each point in the grid.
    """

    # Keep track of the number of points in the x and y directions.
    x_len = len(x)
    y_len = len(y)

    # Create a 2D grid of points. X and Y are 2D arrays with a shape of (y_len, x_len).
    X, Y = np.meshgrid(x, y)

    # Instead of calculating the function value for each point of the grid, utilise
    # the library's SIMD capabilities and calculate function values for all points in
    # a single function call. For this, re-arrange and concatenate the X and Y matrices
    # into a single matrix with 2 columns, where x values are stored in the first
    # column and y values are stored in the second column, adhering to the function's
    # input format.
    m = np.array([X.reshape(-1), Y.reshape(-1)]).T
    Z = fcn(m)

    # Reshape the 1D array of function values into a 2D array with the same shape
    # as X and Y.
    Z = Z.reshape(y_len, x_len)

    return X, Y, Z
