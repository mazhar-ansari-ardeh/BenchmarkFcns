benchmarkfcns.zerosum
=====================

.. currentmodule:: benchmarkfcns

.. autofunction:: zerosum

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   f(\textbf{x}) = \cases {0 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\text{if} ~\sum_{i=1}^nx_i=0 \\
1 + (10000\mid \sum_{i=1}^n x_i \mid)^{0.5} ~~~~\text{otherwise}}

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.zerosum
