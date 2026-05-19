benchmarkfcns.multiobjective.mop2
=================================

.. currentmodule:: benchmarkfcns.multiobjective

.. autofunction:: mop2

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   \begin{aligned}
f_1(\textbf{x}) &= 1 - \exp(-\sum_{i=1}^n (x_i - \frac{1}{\sqrt{n}})^2) \\
f_2(\textbf{x}) &= 1 - \exp(-\sum_{i=1}^n (x_i + \frac{1}{\sqrt{n}})^2)
\end{aligned}

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.multiobjective.mop2
