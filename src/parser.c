#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 26
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3

enum {
  anon_sym_BASE = 1,
  anon_sym_PREFIX = 2,
  anon_sym_SELECT = 3,
  anon_sym_CONSTRUCT = 4,
  anon_sym_DESCRIBE = 5,
  anon_sym_ASK = 6,
  anon_sym_VALUES = 7,
  anon_sym_LT = 8,
  aux_sym_iri_reference_token1 = 9,
  anon_sym_GT = 10,
  anon_sym_COLON = 11,
  sym_query_unit = 12,
  sym_query = 13,
  sym_prologue = 14,
  sym_base_declaration = 15,
  sym_prefix_declaration = 16,
  sym_select_query = 17,
  sym_select_clause = 18,
  sym_construct_query = 19,
  sym_describe_query = 20,
  sym_ask_query = 21,
  sym_values_clause = 22,
  sym_iri_reference = 23,
  sym_pname_ns = 24,
  aux_sym_prologue_repeat1 = 25,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_BASE] = "BASE",
  [anon_sym_PREFIX] = "PREFIX",
  [anon_sym_SELECT] = "SELECT",
  [anon_sym_CONSTRUCT] = "CONSTRUCT",
  [anon_sym_DESCRIBE] = "DESCRIBE",
  [anon_sym_ASK] = "ASK",
  [anon_sym_VALUES] = "VALUES",
  [anon_sym_LT] = "<",
  [aux_sym_iri_reference_token1] = "iri_reference_token1",
  [anon_sym_GT] = ">",
  [anon_sym_COLON] = ":",
  [sym_query_unit] = "query_unit",
  [sym_query] = "query",
  [sym_prologue] = "prologue",
  [sym_base_declaration] = "base_declaration",
  [sym_prefix_declaration] = "prefix_declaration",
  [sym_select_query] = "select_query",
  [sym_select_clause] = "select_clause",
  [sym_construct_query] = "construct_query",
  [sym_describe_query] = "describe_query",
  [sym_ask_query] = "ask_query",
  [sym_values_clause] = "values_clause",
  [sym_iri_reference] = "iri_reference",
  [sym_pname_ns] = "pname_ns",
  [aux_sym_prologue_repeat1] = "prologue_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_BASE] = anon_sym_BASE,
  [anon_sym_PREFIX] = anon_sym_PREFIX,
  [anon_sym_SELECT] = anon_sym_SELECT,
  [anon_sym_CONSTRUCT] = anon_sym_CONSTRUCT,
  [anon_sym_DESCRIBE] = anon_sym_DESCRIBE,
  [anon_sym_ASK] = anon_sym_ASK,
  [anon_sym_VALUES] = anon_sym_VALUES,
  [anon_sym_LT] = anon_sym_LT,
  [aux_sym_iri_reference_token1] = aux_sym_iri_reference_token1,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_query_unit] = sym_query_unit,
  [sym_query] = sym_query,
  [sym_prologue] = sym_prologue,
  [sym_base_declaration] = sym_base_declaration,
  [sym_prefix_declaration] = sym_prefix_declaration,
  [sym_select_query] = sym_select_query,
  [sym_select_clause] = sym_select_clause,
  [sym_construct_query] = sym_construct_query,
  [sym_describe_query] = sym_describe_query,
  [sym_ask_query] = sym_ask_query,
  [sym_values_clause] = sym_values_clause,
  [sym_iri_reference] = sym_iri_reference,
  [sym_pname_ns] = sym_pname_ns,
  [aux_sym_prologue_repeat1] = aux_sym_prologue_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_BASE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PREFIX] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SELECT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CONSTRUCT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DESCRIBE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ASK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VALUES] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_iri_reference_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_query_unit] = {
    .visible = true,
    .named = true,
  },
  [sym_query] = {
    .visible = true,
    .named = true,
  },
  [sym_prologue] = {
    .visible = true,
    .named = true,
  },
  [sym_base_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_prefix_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_select_query] = {
    .visible = true,
    .named = true,
  },
  [sym_select_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_construct_query] = {
    .visible = true,
    .named = true,
  },
  [sym_describe_query] = {
    .visible = true,
    .named = true,
  },
  [sym_ask_query] = {
    .visible = true,
    .named = true,
  },
  [sym_values_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_iri_reference] = {
    .visible = true,
    .named = true,
  },
  [sym_pname_ns] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_prologue_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(36);
      if (lookahead == ':') ADVANCE(47);
      if (lookahead == '<') ADVANCE(44);
      if (lookahead == '>') ADVANCE(46);
      if (lookahead == 'A') ADVANCE(25);
      if (lookahead == 'B') ADVANCE(1);
      if (lookahead == 'C') ADVANCE(21);
      if (lookahead == 'D') ADVANCE(12);
      if (lookahead == 'P') ADVANCE(24);
      if (lookahead == 'S') ADVANCE(7);
      if (lookahead == 'V') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'A') ADVANCE(29);
      END_STATE();
    case 2:
      if (lookahead == 'A') ADVANCE(18);
      END_STATE();
    case 3:
      if (lookahead == 'B') ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == 'C') ADVANCE(23);
      END_STATE();
    case 5:
      if (lookahead == 'C') ADVANCE(30);
      END_STATE();
    case 6:
      if (lookahead == 'C') ADVANCE(31);
      END_STATE();
    case 7:
      if (lookahead == 'E') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == 'E') ADVANCE(14);
      END_STATE();
    case 9:
      if (lookahead == 'E') ADVANCE(37);
      END_STATE();
    case 10:
      if (lookahead == 'E') ADVANCE(41);
      END_STATE();
    case 11:
      if (lookahead == 'E') ADVANCE(5);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(26);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(28);
      END_STATE();
    case 14:
      if (lookahead == 'F') ADVANCE(15);
      END_STATE();
    case 15:
      if (lookahead == 'I') ADVANCE(35);
      END_STATE();
    case 16:
      if (lookahead == 'I') ADVANCE(3);
      END_STATE();
    case 17:
      if (lookahead == 'K') ADVANCE(42);
      END_STATE();
    case 18:
      if (lookahead == 'L') ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == 'L') ADVANCE(11);
      END_STATE();
    case 20:
      if (lookahead == 'N') ADVANCE(27);
      END_STATE();
    case 21:
      if (lookahead == 'O') ADVANCE(20);
      END_STATE();
    case 22:
      if (lookahead == 'R') ADVANCE(34);
      END_STATE();
    case 23:
      if (lookahead == 'R') ADVANCE(16);
      END_STATE();
    case 24:
      if (lookahead == 'R') ADVANCE(8);
      END_STATE();
    case 25:
      if (lookahead == 'S') ADVANCE(17);
      END_STATE();
    case 26:
      if (lookahead == 'S') ADVANCE(4);
      END_STATE();
    case 27:
      if (lookahead == 'S') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 'S') ADVANCE(43);
      END_STATE();
    case 29:
      if (lookahead == 'S') ADVANCE(9);
      END_STATE();
    case 30:
      if (lookahead == 'T') ADVANCE(39);
      END_STATE();
    case 31:
      if (lookahead == 'T') ADVANCE(40);
      END_STATE();
    case 32:
      if (lookahead == 'T') ADVANCE(22);
      END_STATE();
    case 33:
      if (lookahead == 'U') ADVANCE(13);
      END_STATE();
    case 34:
      if (lookahead == 'U') ADVANCE(6);
      END_STATE();
    case 35:
      if (lookahead == 'X') ADVANCE(38);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_BASE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_PREFIX);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_SELECT);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_CONSTRUCT);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_DESCRIBE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_ASK);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_VALUES);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_iri_reference_token1);
      if (lookahead != 0 &&
          (lookahead < 0 || ' ' < lookahead) &&
          lookahead != '"' &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != '\\' &&
          lookahead != '^' &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 45},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_BASE] = ACTIONS(1),
    [anon_sym_PREFIX] = ACTIONS(1),
    [anon_sym_SELECT] = ACTIONS(1),
    [anon_sym_CONSTRUCT] = ACTIONS(1),
    [anon_sym_DESCRIBE] = ACTIONS(1),
    [anon_sym_ASK] = ACTIONS(1),
    [anon_sym_VALUES] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_query_unit] = STATE(18),
    [sym_query] = STATE(19),
    [sym_prologue] = STATE(2),
    [sym_base_declaration] = STATE(4),
    [sym_prefix_declaration] = STATE(4),
    [sym_select_query] = STATE(9),
    [sym_select_clause] = STATE(11),
    [sym_construct_query] = STATE(9),
    [sym_describe_query] = STATE(9),
    [sym_ask_query] = STATE(9),
    [aux_sym_prologue_repeat1] = STATE(4),
    [anon_sym_BASE] = ACTIONS(3),
    [anon_sym_PREFIX] = ACTIONS(5),
    [anon_sym_SELECT] = ACTIONS(7),
    [anon_sym_CONSTRUCT] = ACTIONS(9),
    [anon_sym_DESCRIBE] = ACTIONS(11),
    [anon_sym_ASK] = ACTIONS(13),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(7), 1,
      anon_sym_SELECT,
    ACTIONS(9), 1,
      anon_sym_CONSTRUCT,
    ACTIONS(11), 1,
      anon_sym_DESCRIBE,
    ACTIONS(13), 1,
      anon_sym_ASK,
    STATE(11), 1,
      sym_select_clause,
    STATE(8), 4,
      sym_select_query,
      sym_construct_query,
      sym_describe_query,
      sym_ask_query,
  [22] = 4,
    ACTIONS(15), 1,
      anon_sym_BASE,
    ACTIONS(18), 1,
      anon_sym_PREFIX,
    STATE(3), 3,
      sym_base_declaration,
      sym_prefix_declaration,
      aux_sym_prologue_repeat1,
    ACTIONS(21), 4,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [40] = 4,
    ACTIONS(3), 1,
      anon_sym_BASE,
    ACTIONS(5), 1,
      anon_sym_PREFIX,
    STATE(3), 3,
      sym_base_declaration,
      sym_prefix_declaration,
      aux_sym_prologue_repeat1,
    ACTIONS(23), 4,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [58] = 1,
    ACTIONS(25), 6,
      anon_sym_BASE,
      anon_sym_PREFIX,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [67] = 1,
    ACTIONS(27), 6,
      anon_sym_BASE,
      anon_sym_PREFIX,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [76] = 1,
    ACTIONS(29), 6,
      anon_sym_BASE,
      anon_sym_PREFIX,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [85] = 3,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      anon_sym_VALUES,
    STATE(25), 1,
      sym_values_clause,
  [95] = 3,
    ACTIONS(33), 1,
      anon_sym_VALUES,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    STATE(23), 1,
      sym_values_clause,
  [105] = 1,
    ACTIONS(37), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [110] = 1,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [115] = 2,
    ACTIONS(41), 1,
      anon_sym_LT,
    STATE(7), 1,
      sym_iri_reference,
  [122] = 2,
    ACTIONS(41), 1,
      anon_sym_LT,
    STATE(6), 1,
      sym_iri_reference,
  [129] = 1,
    ACTIONS(43), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [134] = 1,
    ACTIONS(45), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [139] = 1,
    ACTIONS(47), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [144] = 2,
    ACTIONS(49), 1,
      anon_sym_COLON,
    STATE(13), 1,
      sym_pname_ns,
  [151] = 1,
    ACTIONS(51), 1,
      ts_builtin_sym_end,
  [155] = 1,
    ACTIONS(53), 1,
      ts_builtin_sym_end,
  [159] = 1,
    ACTIONS(55), 1,
      aux_sym_iri_reference_token1,
  [163] = 1,
    ACTIONS(57), 1,
      anon_sym_LT,
  [167] = 1,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
  [171] = 1,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
  [175] = 1,
    ACTIONS(61), 1,
      anon_sym_GT,
  [179] = 1,
    ACTIONS(63), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 22,
  [SMALL_STATE(4)] = 40,
  [SMALL_STATE(5)] = 58,
  [SMALL_STATE(6)] = 67,
  [SMALL_STATE(7)] = 76,
  [SMALL_STATE(8)] = 85,
  [SMALL_STATE(9)] = 95,
  [SMALL_STATE(10)] = 105,
  [SMALL_STATE(11)] = 110,
  [SMALL_STATE(12)] = 115,
  [SMALL_STATE(13)] = 122,
  [SMALL_STATE(14)] = 129,
  [SMALL_STATE(15)] = 134,
  [SMALL_STATE(16)] = 139,
  [SMALL_STATE(17)] = 144,
  [SMALL_STATE(18)] = 151,
  [SMALL_STATE(19)] = 155,
  [SMALL_STATE(20)] = 159,
  [SMALL_STATE(21)] = 163,
  [SMALL_STATE(22)] = 167,
  [SMALL_STATE(23)] = 171,
  [SMALL_STATE(24)] = 175,
  [SMALL_STATE(25)] = 179,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prologue_repeat1, 2), SHIFT_REPEAT(12),
  [18] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prologue_repeat1, 2), SHIFT_REPEAT(17),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prologue_repeat1, 2),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prologue, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_iri_reference, 3),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prefix_declaration, 3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_declaration, 2),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 2),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_describe_query, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_query, 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ask_query, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_query, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_clause, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [51] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_unit, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pname_ns, 1),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_values_clause, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_sparql(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .alias_map = ts_non_terminal_alias_map,
    .state_count = STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
