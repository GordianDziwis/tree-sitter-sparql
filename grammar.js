// [160]
const ECHAR = /\\\\[tbnrf\\"']/

// [162]
const WS = [
  /\x20/,
  /\x09/,
  /\x0D/,
  /\x0A/
]

// [164]
const PN_CHARS_BASE = [
  /[A-Z]/,
  /[a-z]/,
  // /[\u00C0-\u00D6]/,
  // /[\u00D8-\u00F6]/,
  // /[\u00F8-\u02FF]/,
  // /[\u0370-\u037D]/,
  // /[\u037F-\u1FFF]/,
  // /[\u200C-\u200D]/,
  // /[\u2070-\u218F]/,
  // /[\u2C00-\u2FEF]/,
  // /[\u3001-\uD7FF]/,
  // /[\uF900-\uFDCF]/,
  // /[\uFDF0-\uFFFD]/,
  // /[\u{10000}-\u{EFFFF}]/u
]

// [165]
const PN_CHARS_U = PN_CHARS_BASE.concat('_')

// [167]
const PN_CHARS = PN_CHARS_U.concat([
  '-',
  /[0-9]/,
  /[\u00B7]/,
  /[\u0300-\u036F]/,
  /[\u203F-\u2040]/
])

// [172]
const HEX = [
  /[0-9]/,
  /[A-F]/,
  /[a-f]/
]

// [173]
const PN_LOCAL_ESC = [
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
].map(char => '\\' + char)

String.prototype.orLowerCase =
  function () {
    return token(choice(this, this.toLowerCase()))
  }

module.exports = grammar({
  name: 'sparql',

  rules: {

    unit: $ => choice(
      $._query,
      $._update
    ),

    // [2]
    _query: $ => seq(
      optional($.prologue),
      choice(
        $.select_query,
        $.construct_query,
        $.describe_query,
        $.ask_query,
      ),
      optional($.values_clause)
    ),

    // [3]
    // [29]
    // [30]
    _update: $ => seq(
      $.prologue,
      optional(seq(
        choice(
          $.load,
          $.clear,
          $.drop,
          $.add,
          $.move,
          $.copy,
          $.create,
          $.insert_data,
          $.delete_data,
          $.delete_where,
          $.modify
        ),
        optional(seq(
          ';',
          $._update
        ))
      ))
    ),

    // [4]
    prologue: $ => repeat1(choice(
      $.base_declaration,
      $.prefix_declaration
    )),

    // [5]
    base_declaration: $ => seq(
      'BASE'.orLowerCase(),
      $.iri_reference
    ),

    // [6]
    prefix_declaration: $ => seq(
      'PREFIX'.orLowerCase(),
      $._namespace,
      $.iri_reference
    ),

    // [7]
    select_query: $ => seq(
      $.select_clause,
      repeat($.dataset_clause),
      $.where_clause,
      optional($.solution_modifier)
    ),

    // [8]
    sub_select: $ => seq(
      $.select_clause,
      $.where_clause,
      optional($.solution_modifier),
      optional($.values_clause)
    ),

    // [9]
    select_clause: $ => seq(
      'SELECT'.orLowerCase(),
      optional(choice(
        'DISTINCT'.orLowerCase(),
        'REDUCE'.orLowerCase()
      )),
      choice(
        repeat1(choice(
          $.var,
          seq('(', $._expression, 'AS'.orLowerCase(), $.var, ')')
        )),
        '*'
      )
    ),

    // [10]
    construct_query: $ => seq(
      'CONSTRUCT'.orLowerCase(),
      choice(
        seq(
          $.construct_template,
          repeat($.dataset_clause),
          $.where_clause,
          optional($.solution_modifier)
        ),
        seq(
          repeat($.dataset_clause),
          'WHERE'.orLowerCase(), '{', $.triples_template, '}',
          optional($.solution_modifier)
        )
      )
    ),

    // [11]
    describe_query: $ => seq(
      'DESCRIBE'.orLowerCase(),
      choice(
        repeat1($._var_or_iri),
        '*'
      ),
      repeat($.dataset_clause),
      optional($.where_clause),
      optional($.solution_modifier)
    ),

    // [12]
    ask_query: $ => seq(
      'ASK'.orLowerCase(),
      repeat($.dataset_clause),
      $.where_clause,
      optional($.solution_modifier)
    ),

    // [13]
    dataset_clause: $ => seq(
      'FROM'.orLowerCase(),
      choice(
        $.default_graph_clause,
        $.named_graph_clause
      )
    ),

    // [14]
    default_graph_clause: $ => $.source_selector,

    // [15]
    named_graph_clause: $ => seq(
      'NAMED'.orLowerCase(),
      $.source_selector
    ),

    // [16]
    source_selector: $ => $._iri,

    // [17]
    where_clause: $ => seq(
      optional('WHERE'.orLowerCase()),
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
      'GROUP'.orLowerCase(),
      'BY'.orLowerCase(),
      repeat1($.group_condition)
    ),

    // [20]
    group_condition: $ => choice(
      $._build_in_call,
      $.function_call,
      seq(
        '(',
        $._expression,
        optional(seq('AS'.orLowerCase(), $.var)),
        ')'
      ),
      $.var
    ),

    // [21]
    having_clause: $ => seq(
      'HAVING'.orLowerCase(),
      repeat1($.having_condition)
    ),

    // [22]
    having_condition: $ => $._constraint,

    // [23]
    order_clause: $ => seq(
      'ORDER'.orLowerCase(),
      'BY'.orLowerCase(),
      repeat1($.order_condition)
    ),

    // [24]
    order_condition: $ => choice(
      seq(
        choice('ASC'.orLowerCase(), 'DESC'.orLowerCase()),
        $.bracketted_expression
      ),
      choice(
        $._constraint,
        $.var
      )
    ),

    // [25]
    limit_offset_clauses: $ => choice(
      seq($.limit_clause, optional($.offset_clause)),
      seq($.offset_clause, optional($.limit_clause)
      )
    ),

    // [26]
    limit_clause: $ => seq(
      'LIMIT'.orLowerCase(),
      $.integer
    ),

    // [27]
    offset_clause: $ => seq(
      'OFFSET'.orLowerCase(),
      $.integer
    ),

    // [28]
    values_clause: $ => seq(
      'VALUES'.orLowerCase(),
      $._data_block
    ),

    // [31]
    load: $ => seq(
      'LOAD'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $._iri,
      optional(seq('INTO'.orLowerCase(), $.graph_ref))
    ),

    // [32]
    clear: $ => seq(
      'CLEAR'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $.graph_ref_all
    ),

    // [33]
    drop: $ => seq(
      'DROP'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $.graph_ref_all
    ),

    // [34]
    create: $ => seq(
      'CREATE'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $.graph_ref
    ),

    // [35]
    add: $ => seq(
      'ADD'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $.graph_or_default,
      'TO'.orLowerCase(),
      $.graph_or_default
    ),

    // [36]
    move: $ => seq(
      'MOVE'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $.graph_or_default,
      'TO'.orLowerCase(),
      $.graph_or_default
    ),

    // [37]
    copy: $ => seq(
      'COPY'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $.graph_or_default,
      'TO'.orLowerCase(),
      $.graph_or_default
    ),

    // [38]
    insert_data: $ => seq('INSERT DATA', $.quads),

    // [39]
    delete_data: $ => seq('DELETE DATA', $.quads),

    // [40]
    delete_where: $ => seq('DELETE WHERE', $.quads),

    // [41]
    modify: $ => seq(
      optional(seq('WITH'.orLowerCase(), $._iri)),
      choice(
        seq($.delete_clause, optional($.insert_clause)),
        $.insert_clause
      ),
      repeat($.using_clause),
      'WHERE'.orLowerCase(),
      $.group_graph_pattern
    ),

    // [42]
    delete_clause: $ => seq('DELETE'.orLowerCase(), $.quads),

    // [43]
    insert_clause: $ => seq('INSERT'.orLowerCase(), $.quads),

    // [44]
    using_clause: $ => seq(
      'USING'.orLowerCase(),
      choice(
        $._iri,
        seq('NAMED'.orLowerCase(), $._iri)
      )
    ),

    // [45]
    graph_or_default: $ => choice(
      'DEFAULT'.orLowerCase(),
      seq(
        optional('GRAPH'.orLowerCase()),
        $._iri)
    ),

    // [46]
    graph_ref: $ => seq('GRAPH'.orLowerCase(), $._iri),

    // [47]
    graph_ref_all: $ => choice(
      $.graph_ref,
      'DEFAULT'.orLowerCase(),
      'NAMED'.orLowerCase(),
      'ALL'.orLowerCase()
    ),

    // [48]
    // [49]
    // [50]
    quads: $ => seq(
      '{',
      optional($.triples_template),
      repeat(seq(
        $.quads_not_triples,
        optional('?'),
        optional($.triples_template),
      )),
      '}'
    ),

    // [51]
    quads_not_triples: $ => seq(
      'GRAPH'.orLowerCase(),
      $._var_or_iri,
      '{',
      optional($.triples_template),
      '}'
    ),

    // [52]
    triples_template: $ => seq(
      $.triples_same_subject,
      optional(seq('.', optional($.triples_template)))
    ),

    // [53]
    // [54]
    group_graph_pattern: $ => seq(
      '{',
      choice(
        $.sub_select,
        seq(
          optional($.triples_block),
          repeat(seq(
            $._graph_pattern_not_triples,
            optional('.'),
            optional($.triples_block)
          ))
        )
      ),
      '}'
    ),

    // [55]
    triples_block: $ => seq(
      $.triples_same_subject_path,
      optional(seq(
        '.',
        optional($.triples_block)
      ))
    ),

    // [56]
    _graph_pattern_not_triples: $ => choice(
      $.group_or_union_graph_pattern,
      $.optional_graph_pattern,
      $.minus_graph_pattern,
      $.graph_graph_pattern,
      $.service_graph_pattern,
      $.filter,
      $.bind,
      $.inline_data
    ),

    // [57]
    optional_graph_pattern: $ => seq('OPTIONAL'.orLowerCase(), $.group_graph_pattern),

    // [58]
    graph_graph_pattern: $ => seq(
      'GRAPH'.orLowerCase(),
      $._var_or_iri,
      $.group_graph_pattern
    ),

    // [59]
    service_graph_pattern: $ => seq(
      'SERVICE'.orLowerCase(),
      optional('SILENT'.orLowerCase()),
      $._var_or_iri,
      $.group_graph_pattern
    ),

    // [60]
    bind: $ => seq(
      'BIND'.orLowerCase(),
      '(',
      $._expression,
      'AS'.orLowerCase(),
      $.var,
      ')'
    ),

    // [61]
    inline_data: $ => seq('VALUES'.orLowerCase(), $._data_block),

    // [62]
    _data_block: $ => choice(
      $.inline_data_one_var,
      $.inline_data_full
    ),

    // [63]
    inline_data_one_var: $ => seq(
      $.var,
      '{',
      repeat($._data_block_value),
      '}'
    ),

    // [64]
    inline_data_full: $ => seq(
      choice(
        $.nil,
        seq('(', repeat1($.var), ')')
      ),
      '{',
      repeat(choice(
        seq('(', repeat1($._data_block_value), ')'),
        $.nil
      )),
      '}'
    ),

    // [65]
    _data_block_value: $ => choice(
      $._iri,
      $.rdf_literal,
      $._numeric_literal,
      $.boolean_literal,
      'UNDEF'.orLowerCase()
    ),

    // [66]
    minus_graph_pattern: $ => seq('MINUS'.orLowerCase(), $.group_graph_pattern),

    // [67]
    group_or_union_graph_pattern: $ => seq(
      $.group_graph_pattern,
      repeat(seq('UNION'.orLowerCase(), $.group_graph_pattern))
    ),

    // [68]
    filter: $ => seq('FILTER'.orLowerCase(), $._constraint),

    // [69]
    _constraint: $ => choice(
      $.bracketted_expression,
      $._build_in_call,
      $.function_call
    ),

    // [70]
    function_call: $ => seq(
      $._iri,
      $.arg_list
    ),

    // [71]
    arg_list: $ => choice(
      $.nil,
      seq(
        '(',
        optional('DISTINCT'.orLowerCase()),
        $._expression,
        repeat(seq(',', $._expression)),
        ')'
      )
    ),

    // [72]
    expression_list: $ => choice(
      $.nil,
      seq(
        '(',
        $._expression,
        repeat(seq(',', $._expression)),
        ')'
      )
    ),

    // [73]
    construct_template: $ => seq(
      '{',
      $.construct_triples,
      '}'
    ),

    // [74]
    construct_triples: $ => seq(
      $.triples_same_subject,
      optional(seq(
        '.',
        optional($.construct_triples)
      ))
    ),

    // [75]
    // [76]
    triples_same_subject: $ => choice(
      seq(
        $._var_or_term,
        $.property_list
      ),
      seq(
        $._triples_node,
        optional($.property_list)
      )
    ),

    // [77]
    // [78]
    property_list: $ => seq(
      field('predicate', choice(
        $._var_or_iri,
        'a'
      )),
      $.object_list,
      repeat(
        seq(
          ';',
          optional(seq(
            field('predicate', choice(
              $._var_or_iri,
              'a'
            )),
            $.object_list
          ))
        )
      )
    ),

    // [79]
    // [80]
    object_list: $ => seq(
      $._graph_node,
      repeat(seq(',', $._graph_node))
    ),

    // [81]
    // [82]
    triples_same_subject_path: $ => choice(
      seq(
        field('subject', $._var_or_term),
        $.property_list_path),
      seq(
        $._triples_node_path,
        optional($.property_list_path)
      )
    ),

    // [83]
    // [84]
    // [85]
    property_list_path: $ => seq(
      field('predicate', choice(
        $._path,
        $.var
      )),
      $.object_list_path,
      repeat(seq(
        ';',
        optional(seq(
          field('predicate', choice(
            $._path,
            $.var
          )),
          $.object_list,
        ))
      ))
    ),

    // [86]
    // [87]
    object_list_path: $ => seq(
      $._graph_node_path,
      repeat(seq(',', $._graph_node_path)
      )
    ),

    // [88 - 92]
    _path: $ => choice(
      $.path_element,
      $.binary_path
    ),

    binary_path: $ => choice(
      prec.left(1, seq($._path, '/', $._path)),
      prec.left(seq($._path, '|', $._path))
    ),

    path_element: $ => seq(
      optional($.path_inverse),
      $._primary_path,
      optional($.path_mod)
    ),

    // [92]
    path_inverse: $ => '^',

    // [93]
    path_mod: $ => token(choice(
      '?',
      '*',
      '+'
    )),

    // [94]
    _primary_path: $ => choice(
      $._iri,
      'a',
      seq('!', $.path_negated_property_set),
      seq('(', $._path, ')')
    ),

    // [95]
    path_negated_property_set: $ => choice(
      $.path_one_in_property_set,
      seq(
        '(',
        optional(seq(
          $.path_one_in_property_set,
          repeat(seq('|', $.path_one_in_property_set)),
        )),
        ')'
      )
    ),

    // [96]
    path_one_in_property_set: $ => choice(
      $._iri,
      'a',
      seq(
        '^',
        choice(
          $._iri,
          'a'
        )
      )
    ),

    // [98]
    _triples_node: $ => choice(
      $.collection,
      $.blank_node_property_list
    ),

    // [99]
    blank_node_property_list: $ => seq(
      '[',
      $.property_list,
      ']'
    ),

    // [100]
    _triples_node_path: $ => choice(
      $.collection_path,
      $.blank_node_property_list_path
    ),

    // [101]
    blank_node_property_list_path: $ => seq(
      '[',
      $.property_list_path,
      ']'
    ),

    // [102]
    collection: $ => seq(
      '(',
      repeat1($._graph_node),
      ')'
    ),

    // [103]
    collection_path: $ => seq(
      '(',
      repeat1($._graph_node_path),
      ')'
    ),

    // [104]
    _graph_node: $ => choice(
      $._var_or_term,
      $._triples_node
    ),

    // [105]
    _graph_node_path: $ => choice(
      $._var_or_term,
      $._triples_node_path
    ),

    // [106]
    _var_or_term: $ => choice(
      $.var,
      $._graph_term
    ),

    // [107]
    _var_or_iri: $ => choice(
      $.var,
      $._iri,
    ),

    // [108, 143, 144, 166]
    var: $ => token(seq(
      choice(
        '?',
        '$'
      ),
      choice(
        ...PN_CHARS_U,
        /[0-9]/
      ),
      repeat(choice(
        ...PN_CHARS_U,
        /[0-9]/,
        /[\u00B7]/,
        /[\u0300-\u036F]/,
        /[\u203F-\u2040]/
      ))
    )),

    // [109]
    _graph_term: $ => choice(
      $._iri,
      $.rdf_literal,
      $._numeric_literal,
      $.boolean_literal,
      $._blank_node,
      $.nil
    ),

    _expression: $ => choice(
      $._primary_expression,
      $.unary_expression,
      $.binary_expression
    ),

    // [110 - 117]
    binary_expression: $ => choice(
      // conditional
      prec.left(seq($._expression, '||', $._expression)),
      prec.left(1, seq($._expression, '&&', $._expression)),
      // relational
      prec.left(2, seq($._expression, '=', $._expression)),
      prec.left(2, seq($._expression, '<', $._expression)),
      prec.left(2, seq($._expression, '>', $._expression)),
      prec.left(2, seq($._expression, '<=', $._expression)),
      prec.left(2, seq($._expression, '>=', $._expression)),
      prec.left(2, seq($._expression, 'IN'.orLowerCase(), $.expression_list)),
      prec.left(2, seq($._expression, 'NOT'.orLowerCase(), 'IN'.orLowerCase(), $.expression_list)),
      // numeric
      prec.left(3, seq($._expression, '+', $._expression)),
      prec.left(3, seq($._expression, '-', $._expression)),
      prec.left(4, seq($._expression, '*', $._expression)),
      prec.left(4, seq($._expression, '/', $._expression)),
    ),

    // [118]
    unary_expression: $ => choice(
      seq('!', $._primary_expression),
      seq('+', $._primary_expression),
      seq('-', $._primary_expression),
    ),

    // [119]
    _primary_expression: $ => choice(
      $.bracketted_expression,
      $._build_in_call,
      $.iri_or_function,
      $.rdf_literal,
      $._numeric_literal,
      $.boolean_literal,
      $.var
    ),

    // [120]
    bracketted_expression: $ => seq(
      '(',
      $._expression,
      ')'
    ),

    // [121]
    _build_in_call: $ => choice(
      $.aggregate,
      seq('STR'.orLowerCase(), $.bracketted_expression),
      seq('LANG'.orLowerCase(), $.bracketted_expression),
      seq('LANGMATCHES'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('DATATYPE'.orLowerCase(), $.bracketted_expression),
      seq('BOUND'.orLowerCase(), '(', $.var, ')'),
      seq('IRI'.orLowerCase(), $.bracketted_expression),
      seq('URI'.orLowerCase(), $.bracketted_expression),
      seq('BNODE'.orLowerCase(), choice(
        $.bracketted_expression,
        $.nil)),
      seq('RAND'.orLowerCase(), $.nil),
      seq('ABS'.orLowerCase(), $.bracketted_expression),
      seq('CEIL'.orLowerCase(), $.bracketted_expression),
      seq('FLOOR'.orLowerCase(), $.bracketted_expression),
      seq('ROUND'.orLowerCase(), $.bracketted_expression),
      seq('CONCAT'.orLowerCase(), $.expression_list),
      $.substring_expression,
      seq('STRLEN'.orLowerCase(), $.bracketted_expression),
      $.string_replace_expression,
      seq('UCASE'.orLowerCase(), $.bracketted_expression),
      seq('LCASE'.orLowerCase(), $.bracketted_expression),
      seq('ENCODE_FOR_URI', $.bracketted_expression),
      seq('CONTAINS'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('STRSTARTS'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('STRENDS'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('STRBEFORE'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('STRAFTER'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('YEAR'.orLowerCase(), $.bracketted_expression),
      seq('MONTH'.orLowerCase(), $.bracketted_expression),
      seq('DAY'.orLowerCase(), $.bracketted_expression),
      seq('HOURS'.orLowerCase(), $.bracketted_expression),
      seq('MINUTES'.orLowerCase(), $.bracketted_expression),
      seq('SECONDS'.orLowerCase(), $.bracketted_expression),
      seq('TIMEZONE'.orLowerCase(), $.bracketted_expression),
      seq('TZ'.orLowerCase(), $.bracketted_expression),
      seq('NOW'.orLowerCase(), $.nil),
      seq('UUID'.orLowerCase(), $.nil),
      seq('STRUUID'.orLowerCase(), $.nil),
      seq('MD5', $.bracketted_expression),
      seq('SHA1', $.bracketted_expression),
      seq('SHA256', $.bracketted_expression),
      seq('SHA384', $.bracketted_expression),
      seq('SHA512', $.bracketted_expression),
      seq('COALESCE'.orLowerCase(), $.expression_list),
      seq('IF'.orLowerCase(), '(', $._expression, ',', $._expression, ',', $._expression, ')'),
      seq('STRLANG'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('STRDT'.orLowerCase(), '(', $._expression, ',', $._expression, ')'),
      seq('sameTerm', '(', $._expression, ',', $._expression, ')'),
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
      'REGEX'.orLowerCase(),
      '(',
      $._expression,
      ',',
      $._expression,
      optional(seq(',', $._expression)),
      ')'
    ),

    // [123]
    substring_expression: $ => seq(
      'SUBSTR'.orLowerCase(),
      '(',
      $._expression,
      ',',
      $._expression,
      optional(seq(',', $._expression)),
      ')'
    ),

    // [124]
    string_replace_expression: $ => seq(
      'REPLACE'.orLowerCase(),
      '(',
      $._expression,
      ',',
      $._expression,
      ',',
      $._expression,
      optional(seq(',', $._expression)),
      ')'
    ),

    // [125]
    exists_func: $ => seq(
      'EXISTS'.orLowerCase(),
      $.group_graph_pattern
    ),

    // [126]
    not_exists_func: $ => seq(
      'NOT'.orLowerCase(),
      'EXISTS'.orLowerCase(),
      $.group_graph_pattern
    ),

    // [127]
    aggregate: $ => choice(
      seq(
        'COUNT'.orLowerCase(), '(',
        optional('DISTINCT'.orLowerCase()),
        choice(
          '*',
          $._expression
        ),
        ')'
      ),
      seq('SUM'.orLowerCase(), '(', optional('DISTINCT'.orLowerCase()), $._expression, ')'),
      seq('MIN'.orLowerCase(), '(', optional('DISTINCT'.orLowerCase()), $._expression, ')'),
      seq('MAX'.orLowerCase(), '(', optional('DISTINCT'.orLowerCase()), $._expression, ')'),
      seq('AVG'.orLowerCase(), '(', optional('DISTINCT'.orLowerCase()), $._expression, ')'),
      seq('SAMPLE'.orLowerCase(), '(', optional('DISTINCT'.orLowerCase()), $._expression, ')'),
      seq(
        'GROUP_CONCAT', '(',
        optional('DISTINCT'.orLowerCase()),
        $._expression,
        optional(seq(';', 'SEPARATOR'.orLowerCase(), '=', $._string)),
        ')'
      ),
    ),

    // [128]
    iri_or_function: $ => seq(
      $._iri,
      optional($.arg_list)
    ),

    // [129]
    rdf_literal: $ => seq(
      field('value', $._string),
      optional(choice(
        $.lang_tag,
        field('datatype', seq('^^', $._iri))
      ))
    ),

    _numeric_literal: $ => choice(
      $.integer,
      $.decimal,
      $.double
    ),

    // [134]
    boolean_literal: $ => choice(
      'true',
      'false'
    ),


    // [135]
    _string: $ => choice(
      $.string_literal1,
      $.string_literal2,
      $.string_literal_long1,
      $.string_literal_long2,
    ),

    // [136]
    _iri: $ => choice(
      $.iri_reference,
      $.prefixed_name
    ),


    // [137]
    // [141]
    prefixed_name: $ => seq(
      $._namespace,
      optional($.pn_local)
    ),

    // [138]
    _blank_node: $ => choice(
      $.blank_node_label,
      $.anon
    ),

    // [139]
    iri_reference: $ => token(seq(
      '<',
      /([^<>"{}|^`\\\x00-\x20])*/,
      '>'
    )),

    // [140]
    _namespace: $ => seq(
      optional($.pn_prefix),
      ':'
    ),

    // [142]
    blank_node_label: $ => token(seq(
      '_:',
      choice(
        ...PN_CHARS_U,
        /[0-9]/
      ),
      optional(seq(
        repeat(prec(1, choice(
          ...PN_CHARS,
          '.'
        ))),
        choice(...PN_CHARS)
      ))
    )),

    // [145]
    lang_tag: $ => token(seq(
      '@', /[a-zA-Z]+/,
      repeat(seq('-', /[a-zA-Z0-9]+/))
    )),

    // [146]
    integer: $ => token(/[0-9]+/),

    // [147]
    decimal: $ => token(seq(/[0-9]*/, '.', /[0-9]+/)),

    // [148]
    // [155]
    double: $ => token(choice(
      seq(/[0-9]+/, '.', /[0-9]*/, seq(/[eE]/, /[+-]?/, /[0-9]+/)),
      seq('.', /[0-9]+/, seq(/[eE]/, /[+-]?/, /[0-9]+/)),
      seq(/[0-9]+/, seq(/[eE]/, /[+-]?/, /[0-9]+/))
    )),

    // [156]
    string_literal1: $ => token(seq(
      "'",
      repeat(choice(
        /[^\x27\x5C\x0A\x0D]/,
        ECHAR
      )),
      "'"
    )),

    // [157]
    string_literal2: $ => token(seq(
      '"',
      repeat(choice(
        /[^\x22\x5C\x0A\x0D]/,
        ECHAR
      )),
      '"',
    )),

    // [158]
    string_literal_long1: $ => token(seq(
      "'''",
      repeat(seq(
        optional(choice(
          "'",
          "''",
        )),
        choice(
          /[^'\\]/,
          ECHAR
        )
      )),
      "'''",
    )),

    // [159]
    string_literal_long2: $ => token(seq(
      '"""',
      repeat(seq(
        optional(choice(
          '"',
          '""',
        )),
        choice(
          /[^"\\]/,
          ECHAR
        )
      )),
      '"""',
    )),

    // [161]
    // [162]
    nil: $ => token(seq(
      '(',
      repeat(choice(...WS)),
      ')'
    )),

    // [163]
    // [162]
    anon: $ => token(seq(
      '[',
      repeat(choice(...WS)),
      ']'
    )),

    // [168]
    pn_prefix: $ => token(seq(
      choice(...PN_CHARS_BASE),
      optional(seq(
        repeat(choice(
          ...PN_CHARS,
          '.'
        )),
        choice(...PN_CHARS)
      ))
    )),

    // [169]
    pn_local: $ => token.immediate(seq(
      choice(
        ...PN_CHARS_U,
        ':',
        /[0-9]/,
        seq('%', choice(...HEX), choice(...HEX)),
        ...PN_LOCAL_ESC
      ),
      optional(seq(
        repeat(choice(
          ...PN_CHARS,
          '.',
          ':',
          seq('%', choice(...HEX), choice(...HEX)),
          ...PN_LOCAL_ESC
        )),
        choice(
          ...PN_CHARS,
          ':',
          seq('%', choice(...HEX), choice(...HEX)),
          ...PN_LOCAL_ESC
        )
      ))
    )),
  }
});


