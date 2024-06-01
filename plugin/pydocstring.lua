local parser_config = require "nvim-treesitter.parsers".get_parser_configs()
parser_config.pydocstring = {
    filetype = nil,
    install_info = {
        -- TODO relative path to this file??
        url = "~/nvim-python-docstrings/tree-sitter-pydocstring",
        files = { "src/parser.c", "src/scanner.c" },
        generate_requires_npm = false,
        requires_generate_from_grammar = false,
    },
}
