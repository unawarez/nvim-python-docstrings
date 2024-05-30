#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 17
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 10
#define ALIAS_COUNT 0
#define TOKEN_COUNT 7
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  aux_sym_docstring_token1 = 1,
  aux_sym_docstring_content_token1 = 2,
  aux_sym_docstring_content_token2 = 3,
  sym__doc_start = 4,
  sym__doc_end = 5,
  sym__indent = 6,
  sym_docstring = 7,
  sym_docstring_content = 8,
  aux_sym_docstring_repeat1 = 9,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_docstring_token1] = "docstring_token1",
  [aux_sym_docstring_content_token1] = "docstring_content_token1",
  [aux_sym_docstring_content_token2] = "docstring_content_token2",
  [sym__doc_start] = "_doc_start",
  [sym__doc_end] = "_doc_end",
  [sym__indent] = "_indent",
  [sym_docstring] = "docstring",
  [sym_docstring_content] = "docstring_content",
  [aux_sym_docstring_repeat1] = "docstring_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_docstring_token1] = aux_sym_docstring_token1,
  [aux_sym_docstring_content_token1] = aux_sym_docstring_content_token1,
  [aux_sym_docstring_content_token2] = aux_sym_docstring_content_token2,
  [sym__doc_start] = sym__doc_start,
  [sym__doc_end] = sym__doc_end,
  [sym__indent] = sym__indent,
  [sym_docstring] = sym_docstring,
  [sym_docstring_content] = sym_docstring_content,
  [aux_sym_docstring_repeat1] = aux_sym_docstring_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_docstring_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_docstring_content_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_docstring_content_token2] = {
    .visible = false,
    .named = false,
  },
  [sym__doc_start] = {
    .visible = false,
    .named = true,
  },
  [sym__doc_end] = {
    .visible = false,
    .named = true,
  },
  [sym__indent] = {
    .visible = false,
    .named = true,
  },
  [sym_docstring] = {
    .visible = true,
    .named = true,
  },
  [sym_docstring_content] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_docstring_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(aux_sym_docstring_token1);
      if (eof) ADVANCE(2);
      if (lookahead == '\n') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(5);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(aux_sym_docstring_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(aux_sym_docstring_content_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(4);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(aux_sym_docstring_content_token2);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 4, .external_lex_state = 3},
  [3] = {.lex_state = 3, .external_lex_state = 4},
  [4] = {.lex_state = 3, .external_lex_state = 4},
  [5] = {.lex_state = 3, .external_lex_state = 4},
  [6] = {.lex_state = 1, .external_lex_state = 3},
  [7] = {.lex_state = 3, .external_lex_state = 4},
  [8] = {.lex_state = 4},
  [9] = {.lex_state = 3, .external_lex_state = 4},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0, .external_lex_state = 3},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0, .external_lex_state = 3},
  [16] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_docstring_token1] = ACTIONS(1),
    [aux_sym_docstring_content_token2] = ACTIONS(1),
    [sym__doc_start] = ACTIONS(1),
    [sym__doc_end] = ACTIONS(1),
    [sym__indent] = ACTIONS(1),
  },
  [1] = {
    [sym_docstring] = STATE(11),
    [sym__doc_start] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(5), 1,
      aux_sym_docstring_content_token1,
    ACTIONS(7), 1,
      sym__doc_end,
    STATE(3), 1,
      sym_docstring_content,
  [10] = 3,
    ACTIONS(9), 1,
      aux_sym_docstring_token1,
    ACTIONS(11), 1,
      sym__indent,
    STATE(4), 1,
      aux_sym_docstring_repeat1,
  [20] = 3,
    ACTIONS(11), 1,
      sym__indent,
    ACTIONS(13), 1,
      aux_sym_docstring_token1,
    STATE(5), 1,
      aux_sym_docstring_repeat1,
  [30] = 3,
    ACTIONS(15), 1,
      aux_sym_docstring_token1,
    ACTIONS(17), 1,
      sym__indent,
    STATE(5), 1,
      aux_sym_docstring_repeat1,
  [40] = 1,
    ACTIONS(20), 2,
      sym__doc_end,
      aux_sym_docstring_content_token2,
  [45] = 1,
    ACTIONS(22), 2,
      sym__indent,
      aux_sym_docstring_token1,
  [50] = 2,
    ACTIONS(5), 1,
      aux_sym_docstring_content_token1,
    STATE(9), 1,
      sym_docstring_content,
  [57] = 1,
    ACTIONS(15), 2,
      sym__indent,
      aux_sym_docstring_token1,
  [62] = 1,
    ACTIONS(24), 1,
      aux_sym_docstring_token1,
  [66] = 1,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
  [70] = 1,
    ACTIONS(28), 1,
      ts_builtin_sym_end,
  [74] = 1,
    ACTIONS(30), 1,
      sym__doc_end,
  [78] = 1,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
  [82] = 1,
    ACTIONS(34), 1,
      sym__doc_end,
  [86] = 1,
    ACTIONS(36), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 10,
  [SMALL_STATE(4)] = 20,
  [SMALL_STATE(5)] = 30,
  [SMALL_STATE(6)] = 40,
  [SMALL_STATE(7)] = 45,
  [SMALL_STATE(8)] = 50,
  [SMALL_STATE(9)] = 57,
  [SMALL_STATE(10)] = 62,
  [SMALL_STATE(11)] = 66,
  [SMALL_STATE(12)] = 70,
  [SMALL_STATE(13)] = 74,
  [SMALL_STATE(14)] = 78,
  [SMALL_STATE(15)] = 82,
  [SMALL_STATE(16)] = 86,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_docstring_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_docstring_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring_content, 2, 0, 0),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [26] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 3, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 5, 0, 0),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 6, 0, 0),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__doc_start = 0,
  ts_external_token__doc_end = 1,
  ts_external_token__indent = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__doc_start] = sym__doc_start,
  [ts_external_token__doc_end] = sym__doc_end,
  [ts_external_token__indent] = sym__indent,
};

static const bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__doc_start] = true,
    [ts_external_token__doc_end] = true,
    [ts_external_token__indent] = true,
  },
  [2] = {
    [ts_external_token__doc_start] = true,
  },
  [3] = {
    [ts_external_token__doc_end] = true,
  },
  [4] = {
    [ts_external_token__indent] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_pydocstring_external_scanner_create(void);
void tree_sitter_pydocstring_external_scanner_destroy(void *);
bool tree_sitter_pydocstring_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_pydocstring_external_scanner_serialize(void *, char *);
void tree_sitter_pydocstring_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_pydocstring(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_pydocstring_external_scanner_create,
      tree_sitter_pydocstring_external_scanner_destroy,
      tree_sitter_pydocstring_external_scanner_scan,
      tree_sitter_pydocstring_external_scanner_serialize,
      tree_sitter_pydocstring_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
