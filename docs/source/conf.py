
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
    # For autosummary generated pages, pagename is usually 'generated/module.function'
    objname = None
    if pagename.startswith("generated/"):
        objname = pagename.split(".")[-1]

    # Fallback to context
    if not objname:
        objname = context.get("objname") or context.get("name")

    if objname:
        import os
        # Base dir is the project root (where assets/ lives)
        # app.srcdir is '.../docs/source'
        base_dir = os.path.abspath(os.path.join(app.srcdir, "../.."))
        plots_dir = os.path.join(base_dir, "assets/plots")

        all_plots = []
        if os.path.exists(plots_dir):
            prefix = objname + "fcn"
            for f in sorted(os.listdir(plots_dir)):
                # We check for exact match or suffix matches like _2, _contour
                if (f == prefix + ".png") or (f.startswith(prefix + "_") and f.endswith(".png")):
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
