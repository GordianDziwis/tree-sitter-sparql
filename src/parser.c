#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 115
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 74
#define ALIAS_COUNT 0
#define TOKEN_COUNT 33
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 7

enum {
  anon_sym_BASE = 1,
  anon_sym_PREFIX = 2,
  anon_sym_SELECT = 3,
  anon_sym_CONSTRUCT = 4,
  anon_sym_WHERE = 5,
  anon_sym_LBRACE = 6,
  anon_sym_RBRACE = 7,
  anon_sym_DESCRIBE = 8,
  anon_sym_STAR = 9,
  anon_sym_ASK = 10,
  anon_sym_FROM = 11,
  anon_sym_GROUP = 12,
  anon_sym_BY = 13,
  anon_sym_LPAREN = 14,
  anon_sym_RPAREN = 15,
  anon_sym_HAVING = 16,
  anon_sym_ORDER = 17,
  anon_sym_LIMIT = 18,
  anon_sym_OFFSET = 19,
  anon_sym_VALUES = 20,
  anon_sym_DOT = 21,
  anon_sym_a = 22,
  anon_sym_LT = 23,
  aux_sym_iri_reference_token1 = 24,
  anon_sym_GT = 25,
  anon_sym_COLON = 26,
  anon_sym_QMARK = 27,
  anon_sym_DOLLAR = 28,
  aux_sym_pn_chars_base_token1 = 29,
  aux_sym_pn_chars_base_token2 = 30,
  anon_sym__ = 31,
  aux_sym_var_name_token1 = 32,
  sym_query_unit = 33,
  sym_query = 34,
  sym_prologue = 35,
  sym_base_declaration = 36,
  sym_prefix_declaration = 37,
  sym_select_query = 38,
  sym_select_clause = 39,
  sym_construct_query = 40,
  sym_describe_query = 41,
  sym_ask_query = 42,
  sym_dataset_clause = 43,
  sym_where_clause = 44,
  sym_solution_modifier = 45,
  sym_group_clause = 46,
  sym_group_condition = 47,
  sym_having_clause = 48,
  sym_order_clause = 49,
  sym_limit_offset_clauses = 50,
  sym_limit_clause = 51,
  sym_offset_clause = 52,
  sym_values_clause = 53,
  sym_triples_template = 54,
  sym_group_graph_pattern = 55,
  sym_construct_template = 56,
  sym_triples_same_subject = 57,
  sym_property_list_not_empty = 58,
  sym_verb = 59,
  sym_triples_node = 60,
  sym_collection = 61,
  sym_var_or_iri = 62,
  sym_iri_reference = 63,
  sym_pname_ns = 64,
  sym_var_1 = 65,
  sym_var_2 = 66,
  sym_pn_chars_base = 67,
  sym_pn_chars_u = 68,
  sym_var_name = 69,
  aux_sym_prologue_repeat1 = 70,
  aux_sym_select_query_repeat1 = 71,
  aux_sym_describe_query_repeat1 = 72,
  aux_sym_group_clause_repeat1 = 73,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_BASE] = "BASE",
  [anon_sym_PREFIX] = "PREFIX",
  [anon_sym_SELECT] = "SELECT",
  [anon_sym_CONSTRUCT] = "CONSTRUCT",
  [anon_sym_WHERE] = "WHERE",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_DESCRIBE] = "DESCRIBE",
  [anon_sym_STAR] = "*",
  [anon_sym_ASK] = "ASK",
  [anon_sym_FROM] = "FROM",
  [anon_sym_GROUP] = "GROUP",
  [anon_sym_BY] = "BY",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_HAVING] = "HAVING",
  [anon_sym_ORDER] = "ORDER",
  [anon_sym_LIMIT] = "LIMIT",
  [anon_sym_OFFSET] = "OFFSET",
  [anon_sym_VALUES] = "VALUES",
  [anon_sym_DOT] = ".",
  [anon_sym_a] = "a",
  [anon_sym_LT] = "<",
  [aux_sym_iri_reference_token1] = "iri_reference_token1",
  [anon_sym_GT] = ">",
  [anon_sym_COLON] = ":",
  [anon_sym_QMARK] = "\?",
  [anon_sym_DOLLAR] = "$",
  [aux_sym_pn_chars_base_token1] = "pn_chars_base_token1",
  [aux_sym_pn_chars_base_token2] = "pn_chars_base_token2",
  [anon_sym__] = "_",
  [aux_sym_var_name_token1] = "var_name_token1",
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
  [sym_dataset_clause] = "dataset_clause",
  [sym_where_clause] = "where_clause",
  [sym_solution_modifier] = "solution_modifier",
  [sym_group_clause] = "group_clause",
  [sym_group_condition] = "group_condition",
  [sym_having_clause] = "having_clause",
  [sym_order_clause] = "order_clause",
  [sym_limit_offset_clauses] = "limit_offset_clauses",
  [sym_limit_clause] = "limit_clause",
  [sym_offset_clause] = "offset_clause",
  [sym_values_clause] = "values_clause",
  [sym_triples_template] = "triples_template",
  [sym_group_graph_pattern] = "group_graph_pattern",
  [sym_construct_template] = "construct_template",
  [sym_triples_same_subject] = "triples_same_subject",
  [sym_property_list_not_empty] = "property_list_not_empty",
  [sym_verb] = "verb",
  [sym_triples_node] = "triples_node",
  [sym_collection] = "collection",
  [sym_var_or_iri] = "var_or_iri",
  [sym_iri_reference] = "iri_reference",
  [sym_pname_ns] = "pname_ns",
  [sym_var_1] = "var_1",
  [sym_var_2] = "var_2",
  [sym_pn_chars_base] = "pn_chars_base",
  [sym_pn_chars_u] = "pn_chars_u",
  [sym_var_name] = "var_name",
  [aux_sym_prologue_repeat1] = "prologue_repeat1",
  [aux_sym_select_query_repeat1] = "select_query_repeat1",
  [aux_sym_describe_query_repeat1] = "describe_query_repeat1",
  [aux_sym_group_clause_repeat1] = "group_clause_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_BASE] = anon_sym_BASE,
  [anon_sym_PREFIX] = anon_sym_PREFIX,
  [anon_sym_SELECT] = anon_sym_SELECT,
  [anon_sym_CONSTRUCT] = anon_sym_CONSTRUCT,
  [anon_sym_WHERE] = anon_sym_WHERE,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_DESCRIBE] = anon_sym_DESCRIBE,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_ASK] = anon_sym_ASK,
  [anon_sym_FROM] = anon_sym_FROM,
  [anon_sym_GROUP] = anon_sym_GROUP,
  [anon_sym_BY] = anon_sym_BY,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_HAVING] = anon_sym_HAVING,
  [anon_sym_ORDER] = anon_sym_ORDER,
  [anon_sym_LIMIT] = anon_sym_LIMIT,
  [anon_sym_OFFSET] = anon_sym_OFFSET,
  [anon_sym_VALUES] = anon_sym_VALUES,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_a] = anon_sym_a,
  [anon_sym_LT] = anon_sym_LT,
  [aux_sym_iri_reference_token1] = aux_sym_iri_reference_token1,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [aux_sym_pn_chars_base_token1] = aux_sym_pn_chars_base_token1,
  [aux_sym_pn_chars_base_token2] = aux_sym_pn_chars_base_token2,
  [anon_sym__] = anon_sym__,
  [aux_sym_var_name_token1] = aux_sym_var_name_token1,
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
  [sym_dataset_clause] = sym_dataset_clause,
  [sym_where_clause] = sym_where_clause,
  [sym_solution_modifier] = sym_solution_modifier,
  [sym_group_clause] = sym_group_clause,
  [sym_group_condition] = sym_group_condition,
  [sym_having_clause] = sym_having_clause,
  [sym_order_clause] = sym_order_clause,
  [sym_limit_offset_clauses] = sym_limit_offset_clauses,
  [sym_limit_clause] = sym_limit_clause,
  [sym_offset_clause] = sym_offset_clause,
  [sym_values_clause] = sym_values_clause,
  [sym_triples_template] = sym_triples_template,
  [sym_group_graph_pattern] = sym_group_graph_pattern,
  [sym_construct_template] = sym_construct_template,
  [sym_triples_same_subject] = sym_triples_same_subject,
  [sym_property_list_not_empty] = sym_property_list_not_empty,
  [sym_verb] = sym_verb,
  [sym_triples_node] = sym_triples_node,
  [sym_collection] = sym_collection,
  [sym_var_or_iri] = sym_var_or_iri,
  [sym_iri_reference] = sym_iri_reference,
  [sym_pname_ns] = sym_pname_ns,
  [sym_var_1] = sym_var_1,
  [sym_var_2] = sym_var_2,
  [sym_pn_chars_base] = sym_pn_chars_base,
  [sym_pn_chars_u] = sym_pn_chars_u,
  [sym_var_name] = sym_var_name,
  [aux_sym_prologue_repeat1] = aux_sym_prologue_repeat1,
  [aux_sym_select_query_repeat1] = aux_sym_select_query_repeat1,
  [aux_sym_describe_query_repeat1] = aux_sym_describe_query_repeat1,
  [aux_sym_group_clause_repeat1] = aux_sym_group_clause_repeat1,
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
  [anon_sym_WHERE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DESCRIBE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ASK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FROM] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GROUP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BY] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_HAVING] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ORDER] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LIMIT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_OFFSET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_VALUES] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_a] = {
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
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_pn_chars_base_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pn_chars_base_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_var_name_token1] = {
    .visible = false,
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
  [sym_dataset_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_where_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_solution_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_group_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_group_condition] = {
    .visible = true,
    .named = true,
  },
  [sym_having_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_order_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_offset_clauses] = {
    .visible = true,
    .named = true,
  },
  [sym_limit_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_offset_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_values_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_triples_template] = {
    .visible = true,
    .named = true,
  },
  [sym_group_graph_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_construct_template] = {
    .visible = true,
    .named = true,
  },
  [sym_triples_same_subject] = {
    .visible = true,
    .named = true,
  },
  [sym_property_list_not_empty] = {
    .visible = true,
    .named = true,
  },
  [sym_verb] = {
    .visible = true,
    .named = true,
  },
  [sym_triples_node] = {
    .visible = true,
    .named = true,
  },
  [sym_collection] = {
    .visible = true,
    .named = true,
  },
  [sym_var_or_iri] = {
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
  [sym_var_1] = {
    .visible = true,
    .named = true,
  },
  [sym_var_2] = {
    .visible = true,
    .named = true,
  },
  [sym_pn_chars_base] = {
    .visible = true,
    .named = true,
  },
  [sym_pn_chars_u] = {
    .visible = true,
    .named = true,
  },
  [sym_var_name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_prologue_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_select_query_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_describe_query_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_group_clause_repeat1] = {
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
      if (eof) ADVANCE(66);
      if (lookahead == '$') ADVANCE(94);
      if (lookahead == '(') ADVANCE(80);
      if (lookahead == ')') ADVANCE(81);
      if (lookahead == '*') ADVANCE(75);
      if (lookahead == '.') ADVANCE(87);
      if (lookahead == ':') ADVANCE(92);
      if (lookahead == '<') ADVANCE(89);
      if (lookahead == '>') ADVANCE(91);
      if (lookahead == '?') ADVANCE(93);
      if (lookahead == 'A') ADVANCE(106);
      if (lookahead == 'B') ADVANCE(96);
      if (lookahead == 'D') ADVANCE(100);
      if (lookahead == 'F') ADVANCE(102);
      if (lookahead == 'G') ADVANCE(105);
      if (lookahead == 'H') ADVANCE(97);
      if (lookahead == 'L') ADVANCE(101);
      if (lookahead == 'O') ADVANCE(103);
      if (lookahead == 'P') ADVANCE(104);
      if (lookahead == 'S') ADVANCE(99);
      if (lookahead == 'V') ADVANCE(98);
      if (lookahead == '_') ADVANCE(108);
      if (lookahead == 'a') ADVANCE(88);
      if (lookahead == '{') ADVANCE(72);
      if (lookahead == '}') ADVANCE(73);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(109);
      if (('C' <= lookahead && lookahead <= 'Z')) ADVANCE(95);
      if (('b' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 1:
      if (lookahead == 'A') ADVANCE(51);
      if (lookahead == 'Y') ADVANCE(79);
      END_STATE();
    case 2:
      if (lookahead == 'A') ADVANCE(62);
      END_STATE();
    case 3:
      if (lookahead == 'A') ADVANCE(31);
      END_STATE();
    case 4:
      if (lookahead == 'B') ADVANCE(12);
      END_STATE();
    case 5:
      if (lookahead == 'C') ADVANCE(46);
      END_STATE();
    case 6:
      if (lookahead == 'C') ADVANCE(55);
      END_STATE();
    case 7:
      if (lookahead == 'C') ADVANCE(57);
      END_STATE();
    case 8:
      if (lookahead == 'D') ADVANCE(16);
      END_STATE();
    case 9:
      if (lookahead == 'E') ADVANCE(32);
      END_STATE();
    case 10:
      if (lookahead == 'E') ADVANCE(21);
      END_STATE();
    case 11:
      if (lookahead == 'E') ADVANCE(67);
      END_STATE();
    case 12:
      if (lookahead == 'E') ADVANCE(74);
      END_STATE();
    case 13:
      if (lookahead == 'E') ADVANCE(71);
      END_STATE();
    case 14:
      if (lookahead == 'E') ADVANCE(49);
      END_STATE();
    case 15:
      if (lookahead == 'E') ADVANCE(6);
      END_STATE();
    case 16:
      if (lookahead == 'E') ADVANCE(43);
      END_STATE();
    case 17:
      if (lookahead == 'E') ADVANCE(50);
      END_STATE();
    case 18:
      if (lookahead == 'E') ADVANCE(56);
      END_STATE();
    case 19:
      if (lookahead == 'E') ADVANCE(47);
      END_STATE();
    case 20:
      if (lookahead == 'F') ADVANCE(22);
      if (lookahead == 'R') ADVANCE(8);
      END_STATE();
    case 21:
      if (lookahead == 'F') ADVANCE(28);
      END_STATE();
    case 22:
      if (lookahead == 'F') ADVANCE(53);
      END_STATE();
    case 23:
      if (lookahead == 'G') ADVANCE(82);
      END_STATE();
    case 24:
      if (lookahead == 'H') ADVANCE(19);
      END_STATE();
    case 25:
      if (lookahead == 'I') ADVANCE(34);
      END_STATE();
    case 26:
      if (lookahead == 'I') ADVANCE(35);
      END_STATE();
    case 27:
      if (lookahead == 'I') ADVANCE(54);
      END_STATE();
    case 28:
      if (lookahead == 'I') ADVANCE(63);
      END_STATE();
    case 29:
      if (lookahead == 'I') ADVANCE(4);
      END_STATE();
    case 30:
      if (lookahead == 'K') ADVANCE(76);
      END_STATE();
    case 31:
      if (lookahead == 'L') ADVANCE(60);
      END_STATE();
    case 32:
      if (lookahead == 'L') ADVANCE(15);
      END_STATE();
    case 33:
      if (lookahead == 'M') ADVANCE(77);
      END_STATE();
    case 34:
      if (lookahead == 'M') ADVANCE(27);
      END_STATE();
    case 35:
      if (lookahead == 'N') ADVANCE(23);
      END_STATE();
    case 36:
      if (lookahead == 'N') ADVANCE(52);
      END_STATE();
    case 37:
      if (lookahead == 'O') ADVANCE(59);
      END_STATE();
    case 38:
      if (lookahead == 'O') ADVANCE(33);
      END_STATE();
    case 39:
      if (lookahead == 'O') ADVANCE(36);
      END_STATE();
    case 40:
      if (lookahead == 'P') ADVANCE(78);
      END_STATE();
    case 41:
      if (lookahead == 'R') ADVANCE(38);
      END_STATE();
    case 42:
      if (lookahead == 'R') ADVANCE(10);
      END_STATE();
    case 43:
      if (lookahead == 'R') ADVANCE(83);
      END_STATE();
    case 44:
      if (lookahead == 'R') ADVANCE(37);
      END_STATE();
    case 45:
      if (lookahead == 'R') ADVANCE(61);
      END_STATE();
    case 46:
      if (lookahead == 'R') ADVANCE(29);
      END_STATE();
    case 47:
      if (lookahead == 'R') ADVANCE(13);
      END_STATE();
    case 48:
      if (lookahead == 'S') ADVANCE(30);
      END_STATE();
    case 49:
      if (lookahead == 'S') ADVANCE(5);
      END_STATE();
    case 50:
      if (lookahead == 'S') ADVANCE(86);
      END_STATE();
    case 51:
      if (lookahead == 'S') ADVANCE(11);
      END_STATE();
    case 52:
      if (lookahead == 'S') ADVANCE(58);
      END_STATE();
    case 53:
      if (lookahead == 'S') ADVANCE(18);
      END_STATE();
    case 54:
      if (lookahead == 'T') ADVANCE(84);
      END_STATE();
    case 55:
      if (lookahead == 'T') ADVANCE(69);
      END_STATE();
    case 56:
      if (lookahead == 'T') ADVANCE(85);
      END_STATE();
    case 57:
      if (lookahead == 'T') ADVANCE(70);
      END_STATE();
    case 58:
      if (lookahead == 'T') ADVANCE(45);
      END_STATE();
    case 59:
      if (lookahead == 'U') ADVANCE(40);
      END_STATE();
    case 60:
      if (lookahead == 'U') ADVANCE(17);
      END_STATE();
    case 61:
      if (lookahead == 'U') ADVANCE(7);
      END_STATE();
    case 62:
      if (lookahead == 'V') ADVANCE(26);
      END_STATE();
    case 63:
      if (lookahead == 'X') ADVANCE(68);
      END_STATE();
    case 64:
      if (lookahead == '_') ADVANCE(108);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(64)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(109);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(95);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      END_STATE();
    case 65:
      if (eof) ADVANCE(66);
      if (lookahead == '$') ADVANCE(94);
      if (lookahead == '(') ADVANCE(80);
      if (lookahead == '*') ADVANCE(75);
      if (lookahead == '?') ADVANCE(93);
      if (lookahead == 'A') ADVANCE(48);
      if (lookahead == 'B') ADVANCE(1);
      if (lookahead == 'C') ADVANCE(39);
      if (lookahead == 'D') ADVANCE(14);
      if (lookahead == 'F') ADVANCE(41);
      if (lookahead == 'G') ADVANCE(44);
      if (lookahead == 'H') ADVANCE(2);
      if (lookahead == 'L') ADVANCE(25);
      if (lookahead == 'O') ADVANCE(20);
      if (lookahead == 'P') ADVANCE(42);
      if (lookahead == 'S') ADVANCE(9);
      if (lookahead == 'V') ADVANCE(3);
      if (lookahead == 'W') ADVANCE(24);
      if (lookahead == 'a') ADVANCE(88);
      if (lookahead == '{') ADVANCE(72);
      if (lookahead == '}') ADVANCE(73);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(65)
      END_STATE();
    case 66:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_BASE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_PREFIX);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_SELECT);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_CONSTRUCT);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_WHERE);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_DESCRIBE);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_ASK);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_FROM);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_GROUP);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_BY);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_HAVING);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_ORDER);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_LIMIT);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_OFFSET);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_VALUES);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_a);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_iri_reference_token1);
      if (lookahead != 0 &&
          (lookahead < 0 || ' ' < lookahead) &&
          lookahead != '"' &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != '\\' &&
          lookahead != '^' &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'A') ADVANCE(51);
      if (lookahead == 'Y') ADVANCE(79);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'A') ADVANCE(62);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'A') ADVANCE(31);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'E') ADVANCE(32);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'E') ADVANCE(49);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'I') ADVANCE(34);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'R') ADVANCE(38);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'R') ADVANCE(8);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'R') ADVANCE(10);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'R') ADVANCE(37);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token1);
      if (lookahead == 'S') ADVANCE(30);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_pn_chars_base_token2);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_var_name_token1);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 65},
  [2] = {.lex_state = 65},
  [3] = {.lex_state = 65},
  [4] = {.lex_state = 65},
  [5] = {.lex_state = 65},
  [6] = {.lex_state = 65},
  [7] = {.lex_state = 65},
  [8] = {.lex_state = 65},
  [9] = {.lex_state = 65},
  [10] = {.lex_state = 65},
  [11] = {.lex_state = 65},
  [12] = {.lex_state = 65},
  [13] = {.lex_state = 65},
  [14] = {.lex_state = 65},
  [15] = {.lex_state = 65},
  [16] = {.lex_state = 65},
  [17] = {.lex_state = 65},
  [18] = {.lex_state = 65},
  [19] = {.lex_state = 65},
  [20] = {.lex_state = 65},
  [21] = {.lex_state = 65},
  [22] = {.lex_state = 65},
  [23] = {.lex_state = 65},
  [24] = {.lex_state = 65},
  [25] = {.lex_state = 65},
  [26] = {.lex_state = 65},
  [27] = {.lex_state = 65},
  [28] = {.lex_state = 65},
  [29] = {.lex_state = 65},
  [30] = {.lex_state = 65},
  [31] = {.lex_state = 65},
  [32] = {.lex_state = 65},
  [33] = {.lex_state = 65},
  [34] = {.lex_state = 65},
  [35] = {.lex_state = 65},
  [36] = {.lex_state = 65},
  [37] = {.lex_state = 65},
  [38] = {.lex_state = 65},
  [39] = {.lex_state = 65},
  [40] = {.lex_state = 65},
  [41] = {.lex_state = 65},
  [42] = {.lex_state = 65},
  [43] = {.lex_state = 64},
  [44] = {.lex_state = 65},
  [45] = {.lex_state = 65},
  [46] = {.lex_state = 65},
  [47] = {.lex_state = 65},
  [48] = {.lex_state = 65},
  [49] = {.lex_state = 65},
  [50] = {.lex_state = 65},
  [51] = {.lex_state = 65},
  [52] = {.lex_state = 64},
  [53] = {.lex_state = 65},
  [54] = {.lex_state = 65},
  [55] = {.lex_state = 65},
  [56] = {.lex_state = 65},
  [57] = {.lex_state = 65},
  [58] = {.lex_state = 65},
  [59] = {.lex_state = 65},
  [60] = {.lex_state = 65},
  [61] = {.lex_state = 65},
  [62] = {.lex_state = 65},
  [63] = {.lex_state = 65},
  [64] = {.lex_state = 65},
  [65] = {.lex_state = 65},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 65},
  [68] = {.lex_state = 65},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 65},
  [71] = {.lex_state = 65},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 65},
  [74] = {.lex_state = 65},
  [75] = {.lex_state = 65},
  [76] = {.lex_state = 65},
  [77] = {.lex_state = 65},
  [78] = {.lex_state = 65},
  [79] = {.lex_state = 65},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 65},
  [82] = {.lex_state = 65},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 65},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 65},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 65},
  [92] = {.lex_state = 65},
  [93] = {.lex_state = 65},
  [94] = {.lex_state = 65},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 90},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 65},
  [111] = {.lex_state = 65},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_BASE] = ACTIONS(1),
    [anon_sym_PREFIX] = ACTIONS(1),
    [anon_sym_SELECT] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_DESCRIBE] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_ASK] = ACTIONS(1),
    [anon_sym_FROM] = ACTIONS(1),
    [anon_sym_GROUP] = ACTIONS(1),
    [anon_sym_BY] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_HAVING] = ACTIONS(1),
    [anon_sym_ORDER] = ACTIONS(1),
    [anon_sym_LIMIT] = ACTIONS(1),
    [anon_sym_VALUES] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_a] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [aux_sym_pn_chars_base_token1] = ACTIONS(1),
    [aux_sym_pn_chars_base_token2] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [aux_sym_var_name_token1] = ACTIONS(1),
  },
  [1] = {
    [sym_query_unit] = STATE(108),
    [sym_query] = STATE(104),
    [sym_prologue] = STATE(33),
    [sym_base_declaration] = STATE(35),
    [sym_prefix_declaration] = STATE(35),
    [sym_select_query] = STATE(65),
    [sym_select_clause] = STATE(47),
    [sym_construct_query] = STATE(65),
    [sym_describe_query] = STATE(65),
    [sym_ask_query] = STATE(65),
    [aux_sym_prologue_repeat1] = STATE(35),
    [anon_sym_BASE] = ACTIONS(3),
    [anon_sym_PREFIX] = ACTIONS(5),
    [anon_sym_SELECT] = ACTIONS(7),
    [anon_sym_CONSTRUCT] = ACTIONS(9),
    [anon_sym_DESCRIBE] = ACTIONS(11),
    [anon_sym_ASK] = ACTIONS(13),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 24,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(21), 1,
      anon_sym_STAR,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    ACTIONS(35), 1,
      anon_sym_QMARK,
    ACTIONS(37), 1,
      anon_sym_DOLLAR,
    STATE(18), 1,
      sym_where_clause,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(74), 1,
      sym_solution_modifier,
    ACTIONS(15), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
    STATE(3), 2,
      sym_var_or_iri,
      aux_sym_describe_query_repeat1,
    STATE(5), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
    STATE(22), 2,
      sym_var_1,
      sym_var_2,
  [77] = 23,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    ACTIONS(35), 1,
      anon_sym_QMARK,
    ACTIONS(37), 1,
      anon_sym_DOLLAR,
    STATE(8), 1,
      sym_where_clause,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(70), 1,
      sym_solution_modifier,
    STATE(73), 1,
      sym_limit_offset_clauses,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
    STATE(6), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
    STATE(7), 2,
      sym_var_or_iri,
      aux_sym_describe_query_repeat1,
    STATE(22), 2,
      sym_var_1,
      sym_var_2,
  [151] = 19,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(8), 1,
      sym_where_clause,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(70), 1,
      sym_solution_modifier,
    STATE(73), 1,
      sym_limit_offset_clauses,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
    STATE(6), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [211] = 19,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(8), 1,
      sym_where_clause,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(70), 1,
      sym_solution_modifier,
    STATE(73), 1,
      sym_limit_offset_clauses,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [271] = 19,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(13), 1,
      sym_where_clause,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(94), 1,
      sym_solution_modifier,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [331] = 5,
    ACTIONS(45), 1,
      anon_sym_QMARK,
    ACTIONS(48), 1,
      anon_sym_DOLLAR,
    STATE(7), 2,
      sym_var_or_iri,
      aux_sym_describe_query_repeat1,
    STATE(22), 2,
      sym_var_1,
      sym_var_2,
    ACTIONS(43), 10,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [358] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(94), 1,
      sym_solution_modifier,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [399] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(77), 1,
      sym_solution_modifier,
    ACTIONS(51), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [440] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(78), 1,
      sym_solution_modifier,
    ACTIONS(53), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [481] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(71), 1,
      sym_solution_modifier,
    STATE(73), 1,
      sym_limit_offset_clauses,
    ACTIONS(55), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [522] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(81), 1,
      sym_solution_modifier,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [563] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(82), 1,
      sym_solution_modifier,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [604] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(84), 1,
      sym_solution_modifier,
    ACTIONS(61), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [645] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(89), 1,
      sym_solution_modifier,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [686] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(92), 1,
      sym_solution_modifier,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [727] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(73), 1,
      sym_limit_offset_clauses,
    STATE(91), 1,
      sym_solution_modifier,
    ACTIONS(67), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [768] = 13,
    ACTIONS(25), 1,
      anon_sym_GROUP,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(26), 1,
      sym_group_clause,
    STATE(34), 1,
      sym_having_clause,
    STATE(38), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(70), 1,
      sym_solution_modifier,
    STATE(73), 1,
      sym_limit_offset_clauses,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [809] = 1,
    ACTIONS(69), 12,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
      anon_sym_QMARK,
      anon_sym_DOLLAR,
  [824] = 1,
    ACTIONS(71), 12,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
      anon_sym_QMARK,
      anon_sym_DOLLAR,
  [839] = 1,
    ACTIONS(73), 12,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
      anon_sym_QMARK,
      anon_sym_DOLLAR,
  [854] = 1,
    ACTIONS(75), 12,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
      anon_sym_QMARK,
      anon_sym_DOLLAR,
  [869] = 1,
    ACTIONS(77), 12,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
      anon_sym_QMARK,
      anon_sym_DOLLAR,
  [884] = 1,
    ACTIONS(79), 12,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
      anon_sym_QMARK,
      anon_sym_DOLLAR,
  [899] = 3,
    ACTIONS(83), 1,
      anon_sym_FROM,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
    ACTIONS(81), 9,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [918] = 10,
    ACTIONS(27), 1,
      anon_sym_HAVING,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(29), 1,
      sym_having_clause,
    STATE(49), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(75), 1,
      sym_limit_offset_clauses,
    ACTIONS(86), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [950] = 1,
    ACTIONS(88), 10,
      ts_builtin_sym_end,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [963] = 3,
    ACTIONS(92), 1,
      anon_sym_LPAREN,
    STATE(31), 2,
      sym_group_condition,
      aux_sym_group_clause_repeat1,
    ACTIONS(90), 6,
      ts_builtin_sym_end,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [979] = 8,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(48), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(93), 1,
      sym_limit_offset_clauses,
    ACTIONS(94), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1005] = 4,
    ACTIONS(96), 1,
      anon_sym_BASE,
    ACTIONS(99), 1,
      anon_sym_PREFIX,
    STATE(30), 3,
      sym_base_declaration,
      sym_prefix_declaration,
      aux_sym_prologue_repeat1,
    ACTIONS(102), 4,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [1023] = 3,
    ACTIONS(106), 1,
      anon_sym_LPAREN,
    STATE(31), 2,
      sym_group_condition,
      aux_sym_group_clause_repeat1,
    ACTIONS(104), 6,
      ts_builtin_sym_end,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1039] = 8,
    ACTIONS(109), 1,
      anon_sym_RBRACE,
    ACTIONS(111), 1,
      anon_sym_LPAREN,
    ACTIONS(113), 1,
      anon_sym_a,
    STATE(69), 1,
      sym_verb,
    STATE(87), 1,
      sym_triples_same_subject,
    STATE(90), 1,
      sym_collection,
    STATE(112), 1,
      sym_triples_template,
    STATE(88), 2,
      sym_property_list_not_empty,
      sym_triples_node,
  [1065] = 6,
    ACTIONS(7), 1,
      anon_sym_SELECT,
    ACTIONS(9), 1,
      anon_sym_CONSTRUCT,
    ACTIONS(11), 1,
      anon_sym_DESCRIBE,
    ACTIONS(13), 1,
      anon_sym_ASK,
    STATE(47), 1,
      sym_select_clause,
    STATE(63), 4,
      sym_select_query,
      sym_construct_query,
      sym_describe_query,
      sym_ask_query,
  [1087] = 8,
    ACTIONS(29), 1,
      anon_sym_ORDER,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(49), 1,
      sym_order_clause,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(75), 1,
      sym_limit_offset_clauses,
    ACTIONS(86), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1113] = 4,
    ACTIONS(3), 1,
      anon_sym_BASE,
    ACTIONS(5), 1,
      anon_sym_PREFIX,
    STATE(30), 3,
      sym_base_declaration,
      sym_prefix_declaration,
      aux_sym_prologue_repeat1,
    ACTIONS(115), 4,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [1131] = 7,
    ACTIONS(111), 1,
      anon_sym_LPAREN,
    ACTIONS(113), 1,
      anon_sym_a,
    STATE(69), 1,
      sym_verb,
    STATE(87), 1,
      sym_triples_same_subject,
    STATE(90), 1,
      sym_collection,
    STATE(106), 1,
      sym_triples_template,
    STATE(88), 2,
      sym_property_list_not_empty,
      sym_triples_node,
  [1154] = 7,
    ACTIONS(111), 1,
      anon_sym_LPAREN,
    ACTIONS(113), 1,
      anon_sym_a,
    STATE(69), 1,
      sym_verb,
    STATE(87), 1,
      sym_triples_same_subject,
    STATE(90), 1,
      sym_collection,
    STATE(102), 1,
      sym_triples_template,
    STATE(88), 2,
      sym_property_list_not_empty,
      sym_triples_node,
  [1177] = 6,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(75), 1,
      sym_limit_offset_clauses,
    ACTIONS(86), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1197] = 6,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    STATE(10), 1,
      sym_where_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(46), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1217] = 1,
    ACTIONS(117), 7,
      ts_builtin_sym_end,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1227] = 1,
    ACTIONS(119), 7,
      ts_builtin_sym_end,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1237] = 1,
    ACTIONS(121), 7,
      ts_builtin_sym_end,
      anon_sym_GROUP,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1247] = 6,
    ACTIONS(125), 1,
      anon_sym__,
    ACTIONS(127), 1,
      aux_sym_var_name_token1,
    STATE(20), 1,
      sym_pn_chars_base,
    STATE(21), 1,
      sym_pn_chars_u,
    STATE(23), 1,
      sym_var_name,
    ACTIONS(123), 2,
      aux_sym_pn_chars_base_token1,
      aux_sym_pn_chars_base_token2,
  [1267] = 1,
    ACTIONS(129), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_HAVING,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1277] = 6,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    STATE(17), 1,
      sym_where_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(50), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1297] = 6,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    STATE(16), 1,
      sym_where_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1317] = 6,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    STATE(12), 1,
      sym_where_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(51), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1337] = 6,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(79), 1,
      sym_limit_offset_clauses,
    ACTIONS(131), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1357] = 6,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(59), 1,
      sym_offset_clause,
    STATE(61), 1,
      sym_limit_clause,
    STATE(93), 1,
      sym_limit_offset_clauses,
    ACTIONS(94), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1377] = 6,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    STATE(14), 1,
      sym_where_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1397] = 6,
    ACTIONS(17), 1,
      anon_sym_WHERE,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    ACTIONS(23), 1,
      anon_sym_FROM,
    STATE(15), 1,
      sym_where_clause,
    STATE(41), 1,
      sym_group_graph_pattern,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1417] = 6,
    ACTIONS(125), 1,
      anon_sym__,
    ACTIONS(127), 1,
      aux_sym_var_name_token1,
    STATE(20), 1,
      sym_pn_chars_base,
    STATE(21), 1,
      sym_pn_chars_u,
    STATE(24), 1,
      sym_var_name,
    ACTIONS(123), 2,
      aux_sym_pn_chars_base_token1,
      aux_sym_pn_chars_base_token2,
  [1437] = 1,
    ACTIONS(133), 6,
      anon_sym_BASE,
      anon_sym_PREFIX,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [1446] = 1,
    ACTIONS(135), 6,
      anon_sym_BASE,
      anon_sym_PREFIX,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [1455] = 5,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(137), 1,
      anon_sym_WHERE,
    ACTIONS(139), 1,
      anon_sym_LBRACE,
    STATE(45), 1,
      sym_construct_template,
    STATE(60), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1472] = 1,
    ACTIONS(141), 6,
      anon_sym_BASE,
      anon_sym_PREFIX,
      anon_sym_SELECT,
      anon_sym_CONSTRUCT,
      anon_sym_DESCRIBE,
      anon_sym_ASK,
  [1481] = 1,
    ACTIONS(143), 5,
      ts_builtin_sym_end,
      anon_sym_ORDER,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1489] = 1,
    ACTIONS(145), 4,
      ts_builtin_sym_end,
      anon_sym_LIMIT,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1496] = 3,
    ACTIONS(31), 1,
      anon_sym_LIMIT,
    STATE(76), 1,
      sym_limit_clause,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1507] = 3,
    ACTIONS(23), 1,
      anon_sym_FROM,
    ACTIONS(149), 1,
      anon_sym_WHERE,
    STATE(25), 2,
      sym_dataset_clause,
      aux_sym_select_query_repeat1,
  [1518] = 3,
    ACTIONS(33), 1,
      anon_sym_OFFSET,
    STATE(76), 1,
      sym_offset_clause,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1529] = 1,
    ACTIONS(151), 3,
      ts_builtin_sym_end,
      anon_sym_OFFSET,
      anon_sym_VALUES,
  [1535] = 3,
    ACTIONS(153), 1,
      ts_builtin_sym_end,
    ACTIONS(155), 1,
      anon_sym_VALUES,
    STATE(109), 1,
      sym_values_clause,
  [1545] = 1,
    ACTIONS(157), 3,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
  [1551] = 3,
    ACTIONS(155), 1,
      anon_sym_VALUES,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
    STATE(114), 1,
      sym_values_clause,
  [1561] = 2,
    ACTIONS(92), 1,
      anon_sym_LPAREN,
    STATE(28), 2,
      sym_group_condition,
      aux_sym_group_clause_repeat1,
  [1569] = 1,
    ACTIONS(161), 3,
      anon_sym_WHERE,
      anon_sym_LBRACE,
      anon_sym_FROM,
  [1575] = 1,
    ACTIONS(163), 3,
      ts_builtin_sym_end,
      anon_sym_LIMIT,
      anon_sym_VALUES,
  [1581] = 1,
    ACTIONS(165), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [1586] = 1,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1591] = 1,
    ACTIONS(167), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1596] = 2,
    ACTIONS(169), 1,
      anon_sym_COLON,
    STATE(95), 1,
      sym_pname_ns,
  [1603] = 1,
    ACTIONS(86), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1608] = 1,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1613] = 1,
    ACTIONS(94), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1618] = 1,
    ACTIONS(171), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1623] = 1,
    ACTIONS(55), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1628] = 1,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1633] = 1,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1638] = 2,
    ACTIONS(175), 1,
      anon_sym_LT,
    STATE(53), 1,
      sym_iri_reference,
  [1645] = 1,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1650] = 1,
    ACTIONS(177), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1655] = 2,
    ACTIONS(19), 1,
      anon_sym_LBRACE,
    STATE(42), 1,
      sym_group_graph_pattern,
  [1662] = 1,
    ACTIONS(51), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1667] = 1,
    ACTIONS(179), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [1672] = 1,
    ACTIONS(181), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [1677] = 2,
    ACTIONS(183), 1,
      anon_sym_RBRACE,
    ACTIONS(185), 1,
      anon_sym_DOT,
  [1684] = 1,
    ACTIONS(187), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [1689] = 1,
    ACTIONS(189), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1694] = 1,
    ACTIONS(191), 2,
      anon_sym_RBRACE,
      anon_sym_DOT,
  [1699] = 1,
    ACTIONS(61), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1704] = 1,
    ACTIONS(193), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1709] = 1,
    ACTIONS(131), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1714] = 1,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      anon_sym_VALUES,
  [1719] = 2,
    ACTIONS(175), 1,
      anon_sym_LT,
    STATE(54), 1,
      sym_iri_reference,
  [1726] = 1,
    ACTIONS(195), 1,
      anon_sym_RPAREN,
  [1730] = 1,
    ACTIONS(197), 1,
      anon_sym_LT,
  [1734] = 1,
    ACTIONS(199), 1,
      aux_sym_iri_reference_token1,
  [1738] = 1,
    ACTIONS(201), 1,
      anon_sym_LBRACE,
  [1742] = 1,
    ACTIONS(203), 1,
      anon_sym_RBRACE,
  [1746] = 1,
    ACTIONS(205), 1,
      anon_sym_LBRACE,
  [1750] = 1,
    ACTIONS(207), 1,
      anon_sym_RBRACE,
  [1754] = 1,
    ACTIONS(209), 1,
      anon_sym_GT,
  [1758] = 1,
    ACTIONS(211), 1,
      ts_builtin_sym_end,
  [1762] = 1,
    ACTIONS(213), 1,
      anon_sym_RPAREN,
  [1766] = 1,
    ACTIONS(215), 1,
      anon_sym_RBRACE,
  [1770] = 1,
    ACTIONS(217), 1,
      anon_sym_RBRACE,
  [1774] = 1,
    ACTIONS(219), 1,
      ts_builtin_sym_end,
  [1778] = 1,
    ACTIONS(221), 1,
      ts_builtin_sym_end,
  [1782] = 1,
    ACTIONS(223), 1,
      anon_sym_BY,
  [1786] = 1,
    ACTIONS(225), 1,
      anon_sym_BY,
  [1790] = 1,
    ACTIONS(227), 1,
      anon_sym_RBRACE,
  [1794] = 1,
    ACTIONS(229), 1,
      ts_builtin_sym_end,
  [1798] = 1,
    ACTIONS(153), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 77,
  [SMALL_STATE(4)] = 151,
  [SMALL_STATE(5)] = 211,
  [SMALL_STATE(6)] = 271,
  [SMALL_STATE(7)] = 331,
  [SMALL_STATE(8)] = 358,
  [SMALL_STATE(9)] = 399,
  [SMALL_STATE(10)] = 440,
  [SMALL_STATE(11)] = 481,
  [SMALL_STATE(12)] = 522,
  [SMALL_STATE(13)] = 563,
  [SMALL_STATE(14)] = 604,
  [SMALL_STATE(15)] = 645,
  [SMALL_STATE(16)] = 686,
  [SMALL_STATE(17)] = 727,
  [SMALL_STATE(18)] = 768,
  [SMALL_STATE(19)] = 809,
  [SMALL_STATE(20)] = 824,
  [SMALL_STATE(21)] = 839,
  [SMALL_STATE(22)] = 854,
  [SMALL_STATE(23)] = 869,
  [SMALL_STATE(24)] = 884,
  [SMALL_STATE(25)] = 899,
  [SMALL_STATE(26)] = 918,
  [SMALL_STATE(27)] = 950,
  [SMALL_STATE(28)] = 963,
  [SMALL_STATE(29)] = 979,
  [SMALL_STATE(30)] = 1005,
  [SMALL_STATE(31)] = 1023,
  [SMALL_STATE(32)] = 1039,
  [SMALL_STATE(33)] = 1065,
  [SMALL_STATE(34)] = 1087,
  [SMALL_STATE(35)] = 1113,
  [SMALL_STATE(36)] = 1131,
  [SMALL_STATE(37)] = 1154,
  [SMALL_STATE(38)] = 1177,
  [SMALL_STATE(39)] = 1197,
  [SMALL_STATE(40)] = 1217,
  [SMALL_STATE(41)] = 1227,
  [SMALL_STATE(42)] = 1237,
  [SMALL_STATE(43)] = 1247,
  [SMALL_STATE(44)] = 1267,
  [SMALL_STATE(45)] = 1277,
  [SMALL_STATE(46)] = 1297,
  [SMALL_STATE(47)] = 1317,
  [SMALL_STATE(48)] = 1337,
  [SMALL_STATE(49)] = 1357,
  [SMALL_STATE(50)] = 1377,
  [SMALL_STATE(51)] = 1397,
  [SMALL_STATE(52)] = 1417,
  [SMALL_STATE(53)] = 1437,
  [SMALL_STATE(54)] = 1446,
  [SMALL_STATE(55)] = 1455,
  [SMALL_STATE(56)] = 1472,
  [SMALL_STATE(57)] = 1481,
  [SMALL_STATE(58)] = 1489,
  [SMALL_STATE(59)] = 1496,
  [SMALL_STATE(60)] = 1507,
  [SMALL_STATE(61)] = 1518,
  [SMALL_STATE(62)] = 1529,
  [SMALL_STATE(63)] = 1535,
  [SMALL_STATE(64)] = 1545,
  [SMALL_STATE(65)] = 1551,
  [SMALL_STATE(66)] = 1561,
  [SMALL_STATE(67)] = 1569,
  [SMALL_STATE(68)] = 1575,
  [SMALL_STATE(69)] = 1581,
  [SMALL_STATE(70)] = 1586,
  [SMALL_STATE(71)] = 1591,
  [SMALL_STATE(72)] = 1596,
  [SMALL_STATE(73)] = 1603,
  [SMALL_STATE(74)] = 1608,
  [SMALL_STATE(75)] = 1613,
  [SMALL_STATE(76)] = 1618,
  [SMALL_STATE(77)] = 1623,
  [SMALL_STATE(78)] = 1628,
  [SMALL_STATE(79)] = 1633,
  [SMALL_STATE(80)] = 1638,
  [SMALL_STATE(81)] = 1645,
  [SMALL_STATE(82)] = 1650,
  [SMALL_STATE(83)] = 1655,
  [SMALL_STATE(84)] = 1662,
  [SMALL_STATE(85)] = 1667,
  [SMALL_STATE(86)] = 1672,
  [SMALL_STATE(87)] = 1677,
  [SMALL_STATE(88)] = 1684,
  [SMALL_STATE(89)] = 1689,
  [SMALL_STATE(90)] = 1694,
  [SMALL_STATE(91)] = 1699,
  [SMALL_STATE(92)] = 1704,
  [SMALL_STATE(93)] = 1709,
  [SMALL_STATE(94)] = 1714,
  [SMALL_STATE(95)] = 1719,
  [SMALL_STATE(96)] = 1726,
  [SMALL_STATE(97)] = 1730,
  [SMALL_STATE(98)] = 1734,
  [SMALL_STATE(99)] = 1738,
  [SMALL_STATE(100)] = 1742,
  [SMALL_STATE(101)] = 1746,
  [SMALL_STATE(102)] = 1750,
  [SMALL_STATE(103)] = 1754,
  [SMALL_STATE(104)] = 1758,
  [SMALL_STATE(105)] = 1762,
  [SMALL_STATE(106)] = 1766,
  [SMALL_STATE(107)] = 1770,
  [SMALL_STATE(108)] = 1774,
  [SMALL_STATE(109)] = 1778,
  [SMALL_STATE(110)] = 1782,
  [SMALL_STATE(111)] = 1786,
  [SMALL_STATE(112)] = 1790,
  [SMALL_STATE(113)] = 1794,
  [SMALL_STATE(114)] = 1798,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_describe_query, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_describe_query, 2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_describe_query, 3),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_describe_query_repeat1, 2),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_describe_query_repeat1, 2), SHIFT_REPEAT(43),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_describe_query_repeat1, 2), SHIFT_REPEAT(52),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_query, 5),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ask_query, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_query, 6),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_query, 2),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_describe_query, 4),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_query, 4),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_query, 3),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ask_query, 3),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_query, 3),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pn_chars_base, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pn_chars_u, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_name, 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_or_iri, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_1, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_2, 2),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_select_query_repeat1, 2),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_select_query_repeat1, 2), SHIFT_REPEAT(27),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_solution_modifier, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dataset_clause, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_group_clause, 3),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_solution_modifier, 2),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prologue_repeat1, 2), SHIFT_REPEAT(80),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prologue_repeat1, 2), SHIFT_REPEAT(72),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prologue_repeat1, 2),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_group_clause_repeat1, 2),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_group_clause_repeat1, 2), SHIFT_REPEAT(96),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_triples_template, 2),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prologue, 1),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_group_graph_pattern, 2),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_where_clause, 1),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_where_clause, 2),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_group_condition, 2),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_solution_modifier, 3),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_base_declaration, 2),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prefix_declaration, 3),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_iri_reference, 3),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_having_clause, 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_order_clause, 2),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_offset_clauses, 1),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_clause, 1),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 2),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_clause, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 1),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_template, 2),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_offset_clause, 1),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_property_list_not_empty, 1),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_construct_query, 7),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_limit_offset_clauses, 2),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_solution_modifier, 4),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_describe_query, 5),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verb, 1),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection, 2),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_triples_template, 1),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_triples_same_subject, 1),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_select_query, 4),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_triples_node, 1),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ask_query, 4),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pname_ns, 1),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query_unit, 1),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [219] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 3),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_triples_template, 3),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_values_clause, 1),
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
