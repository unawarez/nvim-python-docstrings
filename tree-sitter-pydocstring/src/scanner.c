#include "tree_sitter/alloc.h"
#include "tree_sitter/parser.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>

enum {
  DOC_START,
  DOC_END,
  INDENT,
};

// smooshing all the state into negative values of indent count. sorry for only
// supporting the first 32767 blanks per line.
typedef int16_t count_t;
const count_t COUNT_MAX = INT16_MAX; // fun fact: -1 >> 1 is still -1
enum {
  STATE_DOC_NOT_STARTED = -1,
  STATE_INDENT_UNKNOWN = -2,
};

struct state {
  count_t count; // needs non-zero init!!
};
const size_t SIZE = sizeof(struct state);
static void init(struct state *p) { p->count = STATE_DOC_NOT_STARTED; }

void *tree_sitter_pydocstring_external_scanner_create() {
  struct state *p = ts_malloc(SIZE);
  init(p);
  return p;
}

const count_t TABSTOP =
    8; // source of inspect.cleandoc -> doc of str.expandtabs
static count_t take_indent_at_most(TSLexer *lex, count_t max) {
  count_t count = 0;
  for (;;) {
    if (lex->lookahead == ' ') {
      lex->advance(lex, false);
      count++;
    } else if (lex->lookahead == '\t') {
      lex->advance(lex, false);
      count = (count + TABSTOP + 1) / TABSTOP;
    } else {
      break;
    }
  }
  return count;
}

bool tree_sitter_pydocstring_external_scanner_scan(void *payload, TSLexer *lex,
                                                   const bool *valid_symbols) {
  struct state *p = payload;
  if (p->count == STATE_DOC_NOT_STARTED) {
    // lexer can only tell you column in the doc, no other positioning. so
    // this is a hack&hope that we will be called before any other node is
    // considered.
    if (valid_symbols[DOC_START]) {
      lex->result_symbol = DOC_START;
      p->count = STATE_INDENT_UNKNOWN;
      return true;
    } else {
      // no DOC_START yet, but it's not even in consideration??
      return false;
    }

  } else if (lex->eof(lex) && valid_symbols[DOC_END]) {
    lex->result_symbol = DOC_END;
    return true;

  } else if (valid_symbols[INDENT]) {
    if (p->count == STATE_INDENT_UNKNOWN) {
      p->count = take_indent_at_most(lex, COUNT_MAX);
      lex->result_symbol = INDENT;
      return true;
    } else {
      assert(p->count >= 0);
      bool ok = take_indent_at_most(lex, p->count) == p->count;
      if (ok) {
        lex->result_symbol = INDENT;
      }
      return ok;
    }

  } else {
    return false;
  }
}

void tree_sitter_pydocstring_external_scanner_destroy(void *payload) {
  return ts_free(payload);
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
