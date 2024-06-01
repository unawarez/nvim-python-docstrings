; idk the difference between opening (docstring vs ((docstring.
; included nvim injection files use a mix of both.
((docstring
  (docstring_content) @injection.content)
  (#set! injection.combined)
  ; (#set! injection.include-children)
  (#set! injection.language "markdown"))
    ; need to define an option for ^language and install this query in lua
