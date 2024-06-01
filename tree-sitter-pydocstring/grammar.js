/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// Replicate Python's `inspect.cleandoc` in parse grammar.
// <https://docs.python.org/3/library/inspect.html#inspect.cleandoc> is the
// cleanest definition. The only node type anyone should see or care about is
// `docstring_content`. Concatenate all those nodes together and reparse them
// as one ReST/Markdown document.
//
// The real algo counts all body lines' indentation first and chooses the
// minimum indentation as what to strip from the entire block. There's no way
// we could look ahead over the whole document. So, an approximation is
// counting the first indent and having a parse error if a subsequent line is
// found to have less. That means we only accept a subset of valid syntax, but
// it's a pretty sane subset at least.

// The cleandoc algorithm, summarized in useful-to-grammar-writers form:
// * All leading whitespace including \n is removed and ignored. The first
//   non-whitespace char is the start of the docstring content.
// * The first line that isn't just whitespace has its indent ignored and removed.
// * Blank lines throughout the meat of the docstring have their \n
//   preserved but all their whitespace is ignored and removed.
// * Non-blank lines 1..N: the minimum indent of all these lines is removed
//   from the beginning of all these lines. As mentioned above, this is not
//   attainable in a grammar. So as an approximation, line 1 has its indent
//   counted and that much indent is removed from all subsequent non-blank
//   lines. A non-blank line 2..N with less indent than line 1 is a parse
//   error. Tabstops are 8 spaces wide when counting these indents, based on a
//   reading of cleandoc source.
// * All trailing whitespace including \n is removed and ignored.

module.exports = grammar({
  name: "pydocstring",

  // extras defaults to whitespace unless overridden!
  extras: $ => [],

  // this whole thing could be implemented as external scanners, but i assume
  // not using regexes will lose tons of performance during editing.
  externals: $ => [
    $._indent,
    // error_state -> return false *has* helped, but not always.
    $.error_state,
  ],

  rules: {
    // finally got an error message mentioning the "start rule",
    // so there is a toplevel rule and it's the first one.
    docstring: $ => choice(
      optional($._headfootspace), // can fail without optional
      seq($._headfootspace, $.docstring_content, optional($._headfootspace)),
      seq($._headfootspace, $.docstring_content,
        repeat1(seq($._indent, $.docstring_content)),
        optional($._headfootspace)),
    ),
    docstring_content: $ => token(prec(0, /[^\n]*\n?/)),
    _headfootspace: $ => token(prec(0, /\s*/)),
  },
});
