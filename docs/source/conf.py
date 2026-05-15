
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

templates_path = ['_templates']
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
html_theme = 'furo'
html_static_path = ['_static']
html_title = "BenchmarkFcns Documentation"
html_baseurl = "https://benchmarkfcns.info"

# -- Extension configuration -------------------------------------------------
# MyST settings for Markdown support
myst_enable_extensions = [
    "amsmath",
    "dollarmath",
]

# Napoleon settings for Google/NumPy style docstrings
napoleon_google_docstring = True
napoleon_numpy_docstring = True
