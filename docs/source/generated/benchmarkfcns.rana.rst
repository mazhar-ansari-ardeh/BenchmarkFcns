benchmarkfcns.rana
==================

.. currentmodule:: benchmarkfcns

.. autofunction:: rana

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   f(\mathbf{x}) = \sum_{i=1}^{n} \left[x_{i} \sin\left(\sqrt{\lvert{x_{1} - x_{i} + 1}\rvert}\right) \cos\left(\sqrt{\lvert{x_{1} + x_{i} + 1}\rvert}\right) + \left(x_{1} + 1\right) \sin\left(\sqrt{\lvert{x_{1} + x_{i} + 1}\rvert}\right) \cos\left(\sqrt{\lvert{x_{1} - x_{i} + 1}\rvert}\right)\right]

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.rana
