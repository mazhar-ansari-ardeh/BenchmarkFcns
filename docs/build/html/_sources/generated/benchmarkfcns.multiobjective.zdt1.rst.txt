benchmarkfcns.multiobjective.zdt1
=================================

.. currentmodule:: benchmarkfcns.multiobjective

.. autofunction:: zdt1

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   f_1(\textbf{x}) = x_1 \\
f_2(\textbf{x}) = g(\textbf{x}) h(f_1, g) \\
g(\textbf{x}) = 1 + \frac{9}{n-1} \sum_{i=2}^{n} x_i \\
h(f_1, g) = 1 - \sqrt{\frac{f_1}{g}}

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.multiobjective.zdt1
