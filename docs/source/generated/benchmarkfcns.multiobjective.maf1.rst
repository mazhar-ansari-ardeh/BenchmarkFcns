benchmarkfcns.multiobjective.maf1
=================================

.. currentmodule:: benchmarkfcns.multiobjective

.. autofunction:: maf1

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   \begin{aligned}
f_i(\textbf{x}) &= 0.5(1 + g(\textbf{x}_M)) [ 1 - \prod_{j=1}^{M-i} x_j \times \begin{cases} 1 - x_{M-i+1} & \text{if } i > 1 \\ 1 & \text{if } i = 1 \end{cases} ] \\
g(\textbf{x}_M) &= \sum_{x_j \in \textbf{x}_M} (x_j - 0.5)^2
\end{aligned}

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.multiobjective.maf1
