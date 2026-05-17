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

{% if available_plots %}
.. list-table::
   :widths: 50 50
   :header-rows: 0
   :class: borderless

   {% for i in range(0, available_plots|length, 2) %}
   * - .. image:: /../../assets/plots/{{ available_plots[i] }}
          :width: 100%
          :align: center
     - {% if i+1 < available_plots|length %}
       .. image:: /../../assets/plots/{{ available_plots[i+1] }}
          :width: 100%
          :align: center
       {% endif %}
   {% endfor %}
{% else %}
No visualization available for this function.
{% endif %}
