{{ fullname | escape | underline }}

.. currentmodule:: {{ module }}

.. autofunction:: {{ objname }}

.. raw:: html

   <div style="clear: both"></div>

{% set tex_file = "src/latex/" + objname + "fcn.tex" %}
{% set plot_file = "assets/" + objname + ".png" %}

.. rubric:: Mathematical Definition

.. math::
   :nowrap:

   {% include tex_file ignore missing %}

.. rubric:: Visualization

.. image:: /../../{{ plot_file }}
   :alt: {{ objname }} landscape
   :align: center
   :width: 600px
