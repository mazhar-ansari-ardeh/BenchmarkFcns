import os
from docutils import nodes
from docutils.parsers.rst import Directive

# -- Project information -----------------------------------------------------
project = 'BenchmarkFcns'
copyright = '2026, Mazhar Ansari Ardeh'
author = 'Mazhar Ansari Ardeh'
release = '4.1.0'

# -- General configuration ---------------------------------------------------
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.viewcode',
    'sphinx.ext.napoleon',
    'sphinx.ext.mathjax',
    'sphinx.ext.autosummary',
    'myst_parser',
    'sphinx_autodoc_typehints',
    'sphinx_sitemap',
]

# Sitemap configuration
html_baseurl = 'https://benchmarkfcns.info/'
sitemap_url_scheme = "{link}"

autodoc_default_options = {
    'members': True,
    'undoc-members': True,
    'imported-members': True,
    'show-inheritance': True,
}

autosummary_generate = True

templates_path = [
    '_templates',
    '../../src/latex',
    '../../src/latex/multiobjective',
    '../../src/latex/multifidelity'
]
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
html_theme = 'furo'
html_static_path = ['_static']
html_css_files = ['custom.css']
html_title = "BenchmarkFcns Documentation"

# -- Extension configuration -------------------------------------------------

class FunctionPlotsDirective(Directive):
    has_content = False
    required_arguments = 1

    def run(self):
        full_name = self.arguments[0]
        objname = full_name.split(".")[-1]
        env = self.state.document.settings.env

        # New plots directory inside docs/source/_static/plots
        plots_dir = os.path.abspath(os.path.join(env.srcdir, "_static/plots"))

        all_plots = []
        if os.path.exists(plots_dir):
            prefix = objname + "fcn"
            for f in sorted(os.listdir(plots_dir)):
                if (f == prefix + ".png") or (f.startswith(prefix + "_") and f.endswith(".png")):
                    all_plots.append(f)

        if not all_plots:
            return [nodes.paragraph('', 'No visualization available for this function.')]

        # Create a list-table for the plots
        table_content = """
.. list-table::
   :widths: 50 50
   :header-rows: 0
   :class: borderless

"""
        for i in range(0, len(all_plots), 2):
            p1 = all_plots[i]
            table_content += f"   * - .. image:: ../_static/plots/{p1}\n          :width: 100%\n          :align: center\n"
            if i + 1 < len(all_plots):
                p2 = all_plots[i+1]
                table_content += f"     - .. image:: ../_static/plots/{p2}\n          :width: 100%\n          :align: center\n"
            else:
                table_content += "     - \n"

        # Parse the generated RST into nodes
        include_lines = table_content.splitlines()
        self.state_machine.insert_input(include_lines, 'function-plots-directive')
        return []

def setup(app):
    app.add_directive("function-plots", FunctionPlotsDirective)

# MyST settings for Markdown support
myst_enable_extensions = [
    "amsmath",
    "dollarmath",
]

# Napoleon settings for Google/NumPy style docstrings
napoleon_google_docstring = True
napoleon_numpy_docstring = True
