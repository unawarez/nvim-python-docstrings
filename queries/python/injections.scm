;extends
([ ; identify which string nodes are really docstrings.
   ; TODO move this into lua, install it via lua, then install it *again* but as highlight queries that disable the default string-literal-pink.
   ; the first three forms can be taken directly from nvim-treesitter/queries/python/highlights.scm.
  (module
  .
  (comment)*
  .
  (expression_statement (string (string_content) @injection.content)))

  (class_definition
    body: (block
      .
      (expression_statement (string (string_content) @injection.content))))

  (function_definition
    body: (block
      .
      (expression_statement (string (string_content) @injection.content))))

  ; module and class attributes.
  ; class attrs can be in the class *or* in __init__.
  ; TODO how to DRY?
  ; module attrs
  (module
    (expression_statement (assignment))
    .
    (expression_statement (string (string_content) @injection.content)))
  ; class attrs
  (class_definition
    body: (block
        (expression_statement (assignment))
        .
        (expression_statement (string (string_content) @injection.content))))
  ; __init__ attrs
  (class_definition
    body: (block
      (function_definition
        name: (identifier) @method-name (#eq? @method-name "__init__")
        body: (block
          (expression_statement (assignment))
          .
          (expression_statement (string (string_content) @injection.content))))))

 ] (#set! injection.language "pydocstring"))
