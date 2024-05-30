#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 8
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 5
#define ALIAS_COUNT 0
#define TOKEN_COUNT 3
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_docstring_content = 1,
  sym__headfootspace = 2,
  sym_docstring = 3,
  aux_sym_docstring_repeat1 = 4,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_docstring_content] = "docstring_content",
  [sym__headfootspace] = "_headfootspace",
  [sym_docstring] = "docstring",
  [aux_sym_docstring_repeat1] = "docstring_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_docstring_content] = sym_docstring_content,
  [sym__headfootspace] = sym__headfootspace,
  [sym_docstring] = sym_docstring,
  [aux_sym_docstring_repeat1] = aux_sym_docstring_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_docstring_content] = {
    .visible = true,
    .named = true,
  },
  [sym__headfootspace] = {
    .visible = false,
    .named = true,
  },
  [sym_docstring] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(sym_docstring_content);
      if (eof) ADVANCE(1);
      if (lookahead == '\n') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(sym_docstring_content);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_docstring_content);
      if (lookahead == '\n') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(sym_docstring_content);
      if (lookahead == '\n') ADVANCE(2);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(sym_docstring_content);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym__headfootspace);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym__headfootspace);
      if (eof) ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 7},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_docstring_content] = ACTIONS(1),
    [sym__headfootspace] = ACTIONS(1),
  },
  [1] = {
    [sym_docstring] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__headfootspace] = ACTIONS(5),
  },
  [2] = {
    [aux_sym_docstring_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(7),
    [sym_docstring_content] = ACTIONS(9),
    [sym__headfootspace] = ACTIONS(11),
  },
  [3] = {
    [aux_sym_docstring_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_docstring_content] = ACTIONS(15),
    [sym__headfootspace] = ACTIONS(17),
  },
  [4] = {
    [aux_sym_docstring_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_docstring_content] = ACTIONS(21),
    [sym__headfootspace] = ACTIONS(24),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
  [4] = 1,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
  [8] = 1,
    ACTIONS(28), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 4,
  [SMALL_STATE(7)] = 8,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 1, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 2, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_docstring_repeat1, 2, 0, 0),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_docstring_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [24] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_docstring_repeat1, 2, 0, 0),
  [26] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_docstring, 3, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
