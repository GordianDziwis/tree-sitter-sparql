module.exports = grammar({
  name: 'sparql',

  rules: {

    // [1]
    query_unit: $ => $.query,

    // [2]
    query: $ => seq(
      optional($.prologue),
      choice(
        $.select_query,
        $.construct_query,
        $.describe_query,
        $.ask_query,
      ),
      optional($.values_clause)
    ),

    // [4]
    prologue: $ => repeat1(choice(
      $.base_declaration,
      $.prefix_declaration
    )),

    // [5]
    base_declaration: $ => seq(
      'BASE',
      $.iri_reference
    ),

    // [6]
    prefix_declaration: $ => seq(
      'PREFIX',
      $.pname_ns,
      $.iri_reference
    ),

    // [7]
    select_query: $ => seq(
      $.select_clause,
      repeat($.dataset_clause),
      $.where_clause,
      optional($.solution_modifier)
    ),

    // [9]
    select_clause: $ => seq(
      'SELECT',
      optional(choice(
        'DISTINCT',
        'REDUCE'
      )),
      choice(
        repeat1(choice(
          $.var,
          seq('(', $.expression, 'AS', $.var, ')')
        )),
        '*'
      )
    ),

    // [10]
    construct_query: $ => seq(
      'CONSTRUCT',
      choice(
        seq(
          $.construct_template,
          repeat($.dataset_clause),
          $.where_clause,
          optional($.solution_modifier)
        ),
        seq(
          repeat($.dataset_clause),
          'WHERE', '{', $.triples_template, '}',
          optional($.solution_modifier)
        )
      )
    ),

    // [11]
    describe_query: $ => seq(
      'DESCRIBE',
      choice(
        repeat1($.var_or_iri),
        '*'
      ),
      repeat($.dataset_clause),
      optional($.where_clause),
      optional($.solution_modifier)
    ),

    // [12]
    ask_query: $ => seq(
      'ASK',
      repeat($.dataset_clause),
      $.where_clause,
      optional($.solution_modifier)
    ),

    // [13]
    dataset_clause: $ => seq(
      'FROM'
      // TODO
    ),

    // [17]
    where_clause: $ => seq(
      optional('WHERE'),
      $.group_graph_pattern
    ),

    // [18]
    solution_modifier: $ => choice(
      // Tree-sitter does not support syntactic rules that match the empty string
      seq(
        $.group_clause,
        optional($.having_clause),
        optional($.order_clause),
        optional($.limit_offset_clauses)
      ),
      seq(
        optional($.group_clause),
        $.having_clause,
        optional($.order_clause),
        optional($.limit_offset_clauses)
      ),
      seq(
        optional($.group_clause),
        optional($.having_clause),
        $.order_clause,
        optional($.limit_offset_clauses)
      ),
      seq(
        optional($.group_clause),
        optional($.having_clause),
        optional($.order_clause),
        $.limit_offset_clauses
      ),
    ),

    // [19]
    group_clause: $ => seq(
      'GROUP',
      'BY',
      repeat1($.group_condition)
    ),

    // [20]
    group_condition: $ => choice(
      // TODO
      seq(
        '(',
        //TODO
        ')'
      ),
      // TODO
    ),

    // [21]
    having_clause: $ => seq(
      'HAVING',
      // TODO
    ),

    // [23]
    order_clause: $ => seq(
      'ORDER',
      'BY',
      // TODO
    ),

    // [25]
    // TODO Hide?
    limit_offset_clauses: $ => choice(
      seq($.limit_clause, optional($.offset_clause)),
      seq($.offset_clause, optional($.limit_clause)
      )
    ),

    // [26]
    limit_clause: $ => seq(
      'LIMIT',
      // TODO
    ),

    // [27]
    offset_clause: $ => seq(
      'OFFSET',
      // TODO
    ),

    // [28]
    values_clause: $ => seq(
      'VALUES',
      // TODO
    ),

    // [52]
    triples_template: $ => seq(
      $.triples_same_subject,
      optional(seq('.', optional($.triples_template)))
    ),

    // [53]
    group_graph_pattern: $ => seq(
      '{',
      // TODO
      '}'
    ),

    // [71]
    arg_list: $ => choice(
      $.nil,
      seq(
        '(',
        optional('DISTINCT'),
        $.expression,
        repeat(seq(',', $.expression)),
        ')'
      )
    ),

    // [72]
    expression_list: $ => choice(
      $.nil,
      seq(
        '(',
        $.expression,
        repeat(seq(',', $.expression)),
        ')'
      )
    ),

    // [73]
    construct_template: $ => seq(
      '{',
      // TODO
      '}'
    ),

    // [75]
    triples_same_subject: $ => choice(
      seq(
        // TODO
        $.property_list_not_empty
      ),
      seq(
        $.triples_node
        // TODO
      )
    ),

    // [77]
    property_list_not_empty: $ => seq(
      $.verb,
      // TODO
    ),

    // [78]
    verb: $ => choice(
      // TODO
      'a'
    ),

    // [98]
    triples_node: $ => choice(
      $.collection,
      // TODO
    ),

    // [102]
    collection: $ => seq(
      '(',
      // TODO
      ')'
    ),

    // [107]
    var_or_iri: $ => choice(
      $.var,
      $.iri,
    ),

    // [108]
    var: $ => choice(
      $.var_1,
      $.var_2,
    ),

    // [110]
    expression: $ => $.conditional_or_expression,

    // [111]
    conditional_or_expression: $ => seq(
      $.conditional_and_expression,
      repeat(seq('||', $.conditional_and_expression))
    ),

    // [112]
    conditional_and_expression: $ => seq(
      $.value_logical,
      repeat(seq('&&', $.value_logical))
    ),

    // [113]
    value_logical: $ => $.relational_expression,

    // [114]
    relational_expression: $ => seq(
      $.numeric_expression,
      optional(choice(
        seq('=', $.numeric_expression),
        seq('!=', $.numeric_expression),
        seq('<', $.numeric_expression),
        seq('>', $.numeric_expression),
        seq('<=', $.numeric_expression),
        seq('>=', $.numeric_expression),
        seq('IN', $.expression_list),
        seq('NOT', 'IN', $.expression_list),
      ))
    ),

    // [115]
    numeric_expression: $ => $.additive_expression,

    // [116]
    additive_expression: $ => seq(
      $.multiplicative_expression,
      repeat(choice(
        seq('+', $.multiplicative_expression),
        seq('-', $.multiplicative_expression),
        seq(
          choice(
            $.numeric_literal_positive,
            $.numeric_literal_negative
          ),
          repeat(choice(
            seq('*', $.unary_expression),
            seq('/', $.unary_expression)
          ))
        )
      ))
    ),

    // [117]
    multiplicative_expression: $ => seq(
      $.unary_expression,
      repeat(choice(
        seq('*', $.unary_expression),
        seq('/', $.unary_expression)
      ))
    ),

    // [118]
    unary_expression: $ => choice(
      seq('!', $.primary_expression),
      seq('+', $.primary_expression),
      seq('-', $.primary_expression),
      $.primary_expression
    ),

    // [119]
    primary_expression: $ => choice(
      $.bracketted_expression,
      $.built_in_call,
      $.iri_or_function,
      $.rdf_literal,
      $.numeric_literal,
      $.boolean_literal,
      $.var
    ),

    // [120]
    bracketted_expression: $ => seq(
      '(',
      $.expression,
      ')'
    ),

    // [121]
    built_in_call: $ => choice(
      $.aggregate,
      seq('STR', $.bracketted_expression),
      seq('LANG', $.bracketted_expression),
      seq('LANGMATCHES', '(', $.expression, ',', $.expression, ')'),
      seq('DATATYPE', $.bracketted_expression),
      seq('BOUND', '(', $.var, ')'),
      seq('IRI', $.bracketted_expression),
      seq('URI', $.bracketted_expression),
      seq('BNODE', choice(
        $.bracketted_expression,
        $.nil)),
      seq('RAND', $.nil),
      seq('ABS', $.bracketted_expression),
      seq('CEIL', $.bracketted_expression),
      seq('FLOOR', $.bracketted_expression),
      seq('ROUND', $.bracketted_expression),
      seq('CONCAT', $.expression_list),
      $.substring_expression,
      seq('STRLEN', $.bracketted_expression),
      $.string_replace_expression,
      seq('UCASE', $.bracketted_expression),
      seq('LCASE', $.bracketted_expression),
      seq('ENCODE_FOR_URI', $.bracketted_expression),
      seq('CONTAINS', '(', $.expression, ',', $.expression, ')'),
      seq('STRSTARTS', '(', $.expression, ',', $.expression, ')'),
      seq('STRENDS', '(', $.expression, ',', $.expression, ')'),
      seq('STRBEFORE', '(', $.expression, ',', $.expression, ')'),
      seq('STRAFTER', '(', $.expression, ',', $.expression, ')'),
      seq('YEAR', $.bracketted_expression),
      seq('MONTH', $.bracketted_expression),
      seq('DAY', $.bracketted_expression),
      seq('HOURS', $.bracketted_expression),
      seq('MINUTES', $.bracketted_expression),
      seq('SECONDS', $.bracketted_expression),
      seq('TIMEZONE', $.bracketted_expression),
      seq('TZ', $.bracketted_expression),
      seq('NOW', $.nil),
      seq('UUID', $.nil),
      seq('STRUUID', $.nil),
      seq('MD5', $.bracketted_expression),
      seq('SHA1', $.bracketted_expression),
      seq('SHA256', $.bracketted_expression),
      seq('SHA384', $.bracketted_expression),
      seq('SHA512', $.bracketted_expression),
      seq('COALESCE', $.expression_list),
      seq('IF', '(', $.expression, ',', $.expression, ',', $.expression, ')'),
      seq('STRLANG', '(', $.expression, ',', $.expression, ')'),
      seq('STRDT', '(', $.expression, ',', $.expression, ')'),
      seq('sameTerm', '(', $.expression, ',', $.expression, ')'),
      seq('isIRI', $.bracketted_expression),
      seq('isURI', $.bracketted_expression),
      seq('isBLANK', $.bracketted_expression),
      seq('isLITERAL', $.bracketted_expression),
      seq('isNUMERIC', $.bracketted_expression),
      $.regex_expression,
      $.exists_func,
      $.not_exists_func
    ),

    // [122]
    regex_expression: $ => seq(
      'REGEX',
      '(',
      $.expression,
      ',',
      $.expression,
      optional(seq(',', $.expression)),
      ')'
    ),

    // [123]
    substring_expression: $ => seq(
      'SUBSTR',
      '(',
      $.expression,
      ',',
      $.expression,
      optional(seq(',', $.expression)),
      ')'
    ),

    // [124]
    string_replace_expression: $ => seq(
      'REPLACE',
      '(',
      $.expression,
      ',',
      $.expression,
      ',',
      $.expression,
      optional(seq(',', $.expression)),
      ')'
    ),

    // [125]
    exists_func: $ => seq(
      'EXISTS',
      $.group_graph_pattern
    ),

    // [126]
    not_exists_func: $ => seq(
      'NOT',
      'EXISTS',
      $.group_graph_pattern
    ),

    // [127]
    aggregate: $ => choice(
      seq(
        'COUNT', '(',
        optional('DISTINCT'),
        choice(
          '*',
          $.expression
        ),
        ')'
      ),
      seq('SUM', '(', optional('DISTINCT'), $.expression, ')'),
      seq('MIN', '(', optional('DISTINCT'), $.expression, ')'),
      seq('MAX', '(', optional('DISTINCT'), $.expression, ')'),
      seq('AVG', '(', optional('DISTINCT'), $.expression, ')'),
      seq('SAMPLE', '(', optional('DISTINCT'), $.expression, ')'),
      seq(
        'GROUP_CONCAT', '(',
        optional('DISTINCT'),
        $.expression,
        optional(seq(';', 'SEPARATOR', '=', $.string)),
        ')'
      ),
    ),

    // [128]
    iri_or_function: $ => seq(
      $.iri,
      optional($.arg_list)
    ),

    // [129]
    rdf_literal: $ => seq(
      $.string,
      optional(choice(
        $.lang_tag,
        seq('^^', $.iri)
      ))
    ),

    // [130]
    numeric_literal: $ => choice(
      $.numeric_literal_unsigned,
      $.numeric_literal_positive,
      $.numeric_literal_negative
    ),

    // [131]
    numeric_literal_unsigned: $ => choice(
      $.integer,
      $.decimal,
      $.double
    ),

    // [132]
    numeric_literal_positive: $ => choice(
      $.integer_positive,
      $.decimal_positive,
      $.double_positive
    ),

    // [133]
    numeric_literal_negative: $ => choice(
      $.integer_negative,
      $.decimal_negative,
      $.double_negative
    ),

    // [134]
    boolean_literal: $ => choice(
      'true',
      'false'
    ),


    // [135]
    string: $ => choice(
      $.string_literal1,
      $.string_literal2,
      $.string_literal_long1,
      $.string_literal_long2,
    ),

    // [136]
    iri: $ => choice(
      $.iri_reference,
      $.prefixed_name
    ),

    // [137]
    prefixed_name: $ => choice(
      $.pname_ns,
      $.pname_ln
    ),

    // [139]
    iri_reference: $ => seq(
      '<',
      /([^<>"{}|^`\\\x00-\x20])*/,
      '>'
    ),

    // [140]
    pname_ns: $ => seq(
      optional($.pn_prefix),
      ':'
    ),

    // [141]
    pname_ln: $ => prec(1, seq(
      $.pname_ns,
      $.pn_local
    )),

    // [143]
    var_1: $ => seq(
      '?',
      $.var_name
    ),

    // [144]
    var_2: $ => seq(
      '$',
      $.var_name
    ),

    // [145]
    lang_tag: $ => token(seq(
      '@', /[a-zA-Z]+/,
      repeat(seq('-', /[a-zA-Z0-9]+/))
    )),

    // [146]
    integer: $ => /[0-9]+/,

    // [147]
    decimal: $ => token(seq(/[0-9]*/, '.', /[0-9]+/)),

    // [148]
    double: $ => choice(
      seq(/[0-9]+/, '.', /[0-9]*/, $.exponent),
      seq('.', /[0-9]+/, $.exponent),
      seq(/[0-9]+/, $.exponent)
    ),

    // [149]
    integer_positive: $ => prec(1, seq('+', $.integer)),

    // [150]
    decimal_positive: $ => prec(1, seq('+', $.decimal)),

    // [151]
    double_positive: $ => prec(1, seq('+', $.double)),

    // [152]
    integer_negative: $ => prec(1, seq('-', $.integer)),

    // [153]
    decimal_negative: $ => prec(1, seq('-', $.decimal)),

    // [154]
    double_negative: $ => prec(1, seq('-', $.double)),

    // [155]
    exponent: $ => token(seq(/[eE]/, /[+-]?/, /[0-9]+/)),

    // [156]
    string_literal1: $ => seq(
      "'",
      repeat(choice(
        /[^\x27\x5C\x0A\x0D]/,
        $.echar
      )),
      "'"
    ),

    // [157]
    string_literal2: $ => seq(
      '"',
      repeat(choice(
        /[^\x22\x5C\x0A\x0D]/,
        $.echar
      )),
      '"',
    ),

    // [158]
    string_literal_long1: $ => seq(
      "'''",
      repeat(seq(
        optional(choice(
          "'",
          "''",
        )),
        choice(
          /[^'\\]/,
          $.echar
        )
      )),
      "'''",
    ),

    // [159]
    string_literal_long2: $ => seq(
      '"""',
      repeat(seq(
        optional(choice(
          '"',
          '""',
        )),
        choice(
          /[^"\\]/,
          $.echar
        )
      )),
      '"""',
    ),

    // [160]
    echar: $ => seq(
      '\\',
      /[tbnrf\\"']/
    ),

    // [161]
    nil: $ => seq(
      '(',
      repeat($.ws),
      ')'
    ),

    // [162]
    ws: $ => choice(
      /\x20/,
      /\x09/,
      /\x0D/,
      /\x0A/
    ),

    // [164]
    pn_chars_base: $ => choice(
      /[A-Z]/,
      /[a-z]/,
      /[\u00C0-\u00D6]/,
      /[\u00D8-\u00F6]/,
      /[\u00F8-\u02FF]/,
      /[\u0370-\u037D]/,
      /[\u037F-\u1FFF]/,
      /[\u200C-\u200D]/,
      /[\u2070-\u218F]/,
      /[\u2C00-\u2FEF]/,
      /[\u3001-\uD7FF]/,
      /[\uF900-\uFDCF]/,
      /[\uFDF0-\uFFFD]/,
      /[\u{10000}-\u{EFFFF}]/u
    ),

    // [165]
    pn_chars_u: $ => choice(
      $.pn_chars_base,
      '_'
    ),

    // [166]
    var_name: $ => prec.right(seq(
      choice(
        $.pn_chars_u,
        /[0-9]/
      ),
      repeat(choice(
        $.pn_chars_u,
        /[0-9]/,
        /[\u00B7]/,
        /[\u0300-\u036F]/,
        /[\u203F-\u2040]/
      ))
    )),

    // [167]
    pn_chars: $ => choice(
      $.pn_chars_u,
      '-',
      /[0-9]/,
      /[\u00B7]/,
      /[\u0300-\u036F]/,
      /[\u203F-\u2040]/
    ),

    // [168]
    pn_prefix: $ => seq(
      $.pn_chars_base,
      optional(seq(
        repeat(choice(
          $.pn_chars,
          '.'
        )),
        $.pn_chars
      ))
    ),

    // [169]
    pn_local: $ => prec.right(seq(
      $.pn_local_start_chars,
      optional($.pn_local_end)
    )),

    pn_local_end: $ => seq(
      repeat($.pn_local_middle_chars),
      $.pn_local_end_chars
    ),


    // [169a]
    pn_local_start_chars: $ => choice(
      $.pn_chars_u,
      ':',
      /[0-9]/,
      $.plx
    ),

    pn_local_middle_chars: $ => prec(1, choice(
      $.pn_chars,
      '.',
      ':',
      $.plx
    )),

    pn_local_end_chars: $ => choice(
      $.pn_chars,
      ':',
      $.plx
    ),

    // [170]
    plx: $ => choice(
      $.percent,
      $.pn_local_esc
    ),

    // [171]
    percent: $ => seq('%', $.hex, $.hex),

    // [172]
    hex: $ => choice(
      /[0-9]/,
      /[A-F]/,
      /[a-f]/
    ),

    // [173]
    pn_local_esc: $ => seq(
      '\\',
      choice(
        '_',
        '~',
        '.',
        '-',
        '!',
        '$',
        '&',
        "'",
        '(',
        ')',
        '*',
        '+',
        ',',
        ';',
        '=',
        '/',
        '?',
        '#',
        '@',
        '%'
      )
    ),

  }
});
