benchmarkfcns.lunacekbirastrigin
================================

.. currentmodule:: benchmarkfcns

.. autofunction:: lunacekbirastrigin

.. raw:: html

   <div style="clear: both"></div>



.. rubric:: Mathematical Definition

.. math::

   \mu_0 = 2.5, \quad s = 1 - \frac{1}{2\sqrt{n+20}-8.2}, \quad \mu_1 = -\sqrt{\frac{\mu_0^2-1}{s}} \\
f(\mathbf{x}) = \min\left(\sum_{i=1}^n (x_i - \mu_0)^2, dn + s \sum_{i=1}^n (x_i - \mu_1)^2\right) + 10 \sum_{i=1}^n (1 - \cos(2\pi(x_i - \mu_0)))

.. rubric:: Visualization

.. function-plots:: benchmarkfcns.lunacekbirastrigin
