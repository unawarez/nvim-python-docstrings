# nvim-python-docstrings

Make Neovim show highlighted markup inside Python docstrings.

This is implemented via a few steps:
1. Add Tree-sitter language injections to capture string literals that are really docstrings.
2. The injected language is a new intermediate `pydocstring` language that hides any
   leading indent in the docstring. This is the key step that prevents docstring
   indentation from ruining the markup, turning it all into code blocks.
3. A second round of language injections turns the non-insignificant-whitespace
   portions of the `pydocstring` into Markdown (sorry; it should be un-hardcoded
   and default to ReST, but I happen to like `pdoc`).


# Dumb mysteries

## Memory corruption

If you open `:InspectTree` in a Python file with multiple docstrings, and then
scroll up/down through the node list, you will see the real document cursor
jumping and looping all over the document. This is obviously not good. Twice
ever, I have seen nvim segfault. I have never seen any suspect behavior while
running Tree-sitter tools on this grammar, *and* the corruption and segfaults
were happening before the grammar had a `scanner.c`, so at this point I assume
it's some horrible undebuggable thing on the nvim side of things.

## Occasionally does nothing, with no error output

Somewhere between 10%-50% of the time, the same file in the same working dir
will not load the injections. Possibly due to memory issues above. I hope.
