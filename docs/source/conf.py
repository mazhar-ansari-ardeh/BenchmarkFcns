
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
    # Print for debugging in CI logs
    # print(f"DEBUG: pagename={pagename}, templatename={templatename}")

    if "function.rst" in templatename:
        objname = context.get("objname")
        if objname:
            import os
            # Try a few ways to find the assets directory
            possible_paths = [
                os.path.abspath(os.path.join(app.srcdir, "../../assets/plots")),
                os.path.abspath(os.path.join(os.getcwd(), "assets/plots")),
                "/home/runner/work/BenchmarkFcns/BenchmarkFcns/assets/plots"
            ]

            plots_dir = None
            for p in possible_paths:
                if os.path.exists(p):
                    plots_dir = p
                    break

            all_plots = []
            if plots_dir:
                prefix = objname + "fcn"
                for f in sorted(os.listdir(plots_dir)):
                    if f.startswith(prefix) and f.endswith(".png"):
                        all_plots.append(f)

            # if not all_plots:
            #    print(f"DEBUG: No plots found for {objname} in {plots_dir}")

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
