{{ fullname | escape | underline }}

.. currentmodule:: {{ module }}

.. autofunction:: {{ objname }}

.. raw:: html

   <div style="clear: both"></div>

{% set tex_file = objname + "fcn.tex" %}

.. rubric:: Mathematical Definition

.. math::

   {% include tex_file ignore missing %}

.. rubric:: Visualization

.. function-plots:: {{ fullname }}
