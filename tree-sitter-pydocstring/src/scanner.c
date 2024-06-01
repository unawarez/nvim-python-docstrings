#include "tree_sitter/alloc.h"
#include "tree_sitter/parser.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>

#if !defined(__EMSCRIPTEN__) && 0
#include <stdio.h>
#define TRACE_INDENT(fmt, ...)                                                 \
  fprintf(stderr, "INDENT: " fmt "\n" __VA_OPT__(, ) __VA_ARGS__)
#else
#define TRACE_INDENT(...) ;
#endif

enum {
  INDENT,
  ERROR_STATE,
};

typedef uint16_t count_t;
const count_t COUNT_MAX = UINT16_MAX - 2;
const count_t COUNT_INVALID_EOF = UINT16_MAX - 1;
const count_t COUNT_BLANK_LINE = UINT16_MAX - 0;

struct state {
  count_t count; // needs non-zero init!!
};
const size_t SIZE = sizeof(struct state);
static void init(struct state *p) { p->count = COUNT_MAX; }

void *tree_sitter_pydocstring_external_scanner_create() {
  struct state *p = ts_malloc(SIZE);
  init(p);
  return p;
}
void tree_sitter_pydocstring_external_scanner_destroy(void *payload) {
  return ts_free(payload);
}

const count_t TABSTOP =
    8; // source of inspect.cleandoc -> doc of str.expandtabs
static count_t take_indent(TSLexer *lex, count_t limit) {
  // even when limit is 0, we want to check for EOF at least.
  // indent should never be able to reach EOF because then docstring_content
  // has nothing to match and it's an error. an indent token can't be created
  // without a docstring_content being able to follow.
  if (lex->eof(lex)) {
    return COUNT_INVALID_EOF;
  }
  count_t count = 0;
  for (; count < limit; count++) {
    if (lex->lookahead == ' ') {
      lex->advance(lex, false);
      count++;
    } else if (lex->lookahead == '\t') {
      lex->advance(lex, false);
      count_t rounded_up = (count + TABSTOP + 1) / TABSTOP;
      count = (rounded_up > count && rounded_up < COUNT_MAX) ? rounded_up
                                                             : COUNT_MAX;
    } else if (lex->eof(lex)) {
      return COUNT_INVALID_EOF;
    } else if (lex->lookahead == '\n') {
      return COUNT_BLANK_LINE;
    } else {
      // some non-indent non-newline text character
      break;
    }
  }
  return count;
}

bool tree_sitter_pydocstring_external_scanner_scan(void *payload, TSLexer *lex,
                                                   const bool *valid_symbols) {
  struct state *p = payload;
  if (valid_symbols[ERROR_STATE]) {
    return false;
  } else if (valid_symbols[INDENT]) {
    // p->count initializes at MAX
    count_t c = take_indent(lex, p->count);
    if (c == COUNT_INVALID_EOF) {
      TRACE_INDENT("eof");
      return false;
    } else if (c == COUNT_BLANK_LINE) {
      // don't care about validating indent of a blank line
      TRACE_INDENT("blank");
      lex->result_symbol = INDENT;
      return true;
    } else if (p->count == COUNT_MAX) {
      // indent not known yet.
      TRACE_INDENT("storing %u", c);
      p->count = c;
      lex->result_symbol = INDENT;
      return true;
    } else {
      // indent count already known.
      if (c == p->count) {
        TRACE_INDENT("matched %u", c);
        lex->result_symbol = INDENT;
        return true;
      } else {
        TRACE_INDENT("failed %u", c);
        return false;
      }
    }
  } else {
    return false;
  }
}

unsigned tree_sitter_pydocstring_external_scanner_serialize(void *payload,
                                                            char *buffer) {
  memcpy(buffer, payload, SIZE);
  return SIZE;
}

void tree_sitter_pydocstring_external_scanner_deserialize(void *payload,
                                                          const char *buffer,
                                                          unsigned length) {
  if (length >= SIZE) {
    memcpy(payload, buffer, SIZE);
  } else {
    init(payload);
  }
}
