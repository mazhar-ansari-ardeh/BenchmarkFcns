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

{% set plot_file = "assets/plots/" + objname + "fcn.png" %}
.. image:: /../../{{ plot_file }}
   :alt: {{ objname }} landscape
   :align: center
   :width: 600px
