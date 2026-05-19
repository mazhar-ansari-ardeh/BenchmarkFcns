Usage Guide
===========

Installation
------------

BenchmarkFcns is available on PyPI:

.. code-block:: bash

   pip install benchmarkfcns

Quick Start
-----------

.. code-block:: python

   from benchmarkfcns import ackley
   import numpy as np

   # Evaluate a single point
   data = np.array([[0, 0, 0]])
   result = ackley(data)
   print(result)

Parallel Execution
------------------

The C++ backend utilizes OpenMP. You can control the number of threads used:

.. code-block:: bash

   export OMP_NUM_THREADS=8
