benchmarkfcns.multiobjective.zdt6
=================================

.. currentmodule:: benchmarkfcns.multiobjective

.. autofunction:: zdt6

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   f_1(\textbf{x}) = 1 - \exp(-4x_1) \sin^6(6\pi x_1) \\
f_2(\textbf{x}) = g(\textbf{x}) h(f_1, g) \\
g(\textbf{x}) = 1 + 9 \left( \frac{\sum_{i=2}^{n} x_i}{n-1} \right)^{0.25} \\
h(f_1, g) = 1 - \left( \frac{f_1}{g} \right)^2

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.multiobjective.zdt6
