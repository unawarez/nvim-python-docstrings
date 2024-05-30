;extends
([ ; these can be taken directly from nvim-treesitter/queries/python/highlights.scm
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
  ] (#set! injection.language "pydocstring"))
