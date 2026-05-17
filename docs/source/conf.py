
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
]

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
html_baseurl = "https://benchmarkfcns.info"

# -- Extension configuration -------------------------------------------------
def add_plots_to_context(app, pagename, templatename, context, doctree):
    if templatename == "autosummary/function.rst":
        objname = context.get("objname")
        if objname:
            import os
            plots_dir = os.path.abspath(os.path.join(app.srcdir, "../../assets/plots"))
            all_plots = []
            if os.path.exists(plots_dir):
                # Find all files starting with objname + "fcn"
                prefix = objname + "fcn"
                for f in sorted(os.listdir(plots_dir)):
                    if f.startswith(prefix) and f.endswith(".png"):
                        # Use a relative path from the doc source to the asset
                        # Sphinx will handle the path resolution
                        all_plots.append(f)
            context["available_plots"] = all_plots

def setup(app):
    app.connect("html-page-context", add_plots_to_context)

# MyST settings for Markdown support
myst_enable_extensions = [
    "amsmath",
    "dollarmath",
]

# Napoleon settings for Google/NumPy style docstrings
napoleon_google_docstring = True
napoleon_numpy_docstring = True
