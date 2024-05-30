local parser_config = require "nvim-treesitter.parsers".get_parser_configs()
parser_config.pydocstring = {
    filetype = nil,
    install_info = {
        -- TODO relative path to this file??
        url = "~/nvim-python-docstrings/tree-sitter-pydocstring", -- local path or git repo
        files = { "src/parser.c" },                               -- note that some parsers also require src/scanner.c or src/scanner.cc
        generate_requires_npm = false,                            -- if stand-alone parser without npm dependencies
        requires_generate_from_grammar = false,                   -- if folder contains pre-generated src/parser.c
    },
}
