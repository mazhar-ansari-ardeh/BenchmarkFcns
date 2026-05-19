benchmarkfcns.multiobjective.viennet3
=====================================

.. currentmodule:: benchmarkfcns.multiobjective

.. autofunction:: viennet3

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   f_1(x_1, x_2) = 0.5(x_1^2 + x_2^2) + \sin(x_1^2 + x_2^2) \\
f_2(x_1, x_2) = \frac{(3x_1 - 2x_2 + 4)^2}{8} + \frac{(x_1 - x_2 + 1)^2}{27} + 15 \\
f_3(x_1, x_2) = \frac{1}{x_1^2 + x_2^2 + 1} - 1.1 \exp(-(x_1^2 + x_2^2))

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.multiobjective.viennet3
