local this_path = debug.getinfo(1, 'S').source:sub(2) -- documented via stackoverflow/reddit, except that the first getinfo param should sometimes be 1 instead of 2.
-- string always starts with a @ for some reason, hence the sub(2).
local plugin_root = vim.fs.joinpath(vim.fs.dirname(this_path), '..')

local parser_config = require "nvim-treesitter.parsers".get_parser_configs()
parser_config.pydocstring = {
    filetype = nil,
    install_info = {
        url = vim.fs.joinpath(plugin_root, "tree-sitter-pydocstring"),
        files = { "src/parser.c", "src/scanner.c" },
        generate_requires_npm = false,
        requires_generate_from_grammar = false,
    },
}
