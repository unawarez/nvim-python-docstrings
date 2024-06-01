# nvim-python-docstrings

A Tree-sitter-based plugin that "natively" styles the markup in Python
docstrings. Live but broken proof-of-concept right now.

People across the internet have set up language injections to do this, but the problem is the captured text will always include any leading indentation in the docstring, and leading indentation is significant/document-breaking in both ReST and Markdown. This plugin fixes that by creating a new `pydocstring` TS language that replicates the indent-skipping behavior of `inspect.cleandoc` as closely as possible. A `python` TS query captures docstrings and injects the `pydocstring` language into them, and then a `pydocstring` TS query captures all the legitimate, non-whitespace docstring text and injects the `markdown` language into them (sorry; should be trivial to make the final language a configurable var though).

Somehow there is memory corruption happening inside nvim. Walking through a document with `:InspectTree` on, you will see as you go up/down the InspectTree list that it bounces all over the document. And once in a great while nvim will segfault while doing this. I have not seen problems running tree-sitter tools on the pydocstring grammar. So I have no clue at this point.
