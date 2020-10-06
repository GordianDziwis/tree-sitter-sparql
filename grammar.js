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
    prologue: $ => repeat1(
      choice(
        $.base_declaration,
        $.prefix_declaration
      )
    ),

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
      'SELECT'
      // TODO
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
          'WHERE',
          '{',
          $.triples_template,
          '}',
          optional($.solution_modifier)
        )
      )
    ),

    // [11]
    describe_query: $ => seq(
      'DESCRIBE',
      optional(
        choice(
          repeat1($.var_or_iri),
          '*'
        )
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
      // TODO
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
      seq(
        $.limit_clause,
        optional($.offset_clause)
      ),
      seq(
        $.offset_clause,
        optional($.limit_clause)
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
      optional(
        seq(
          '.',
          optional($.triples_template)
        )
      )
    ),

    // [53]
    group_graph_pattern: $ => seq(
      '{',
      // TODO
      '}'
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
      $.var_1,
      $.var_2,
    ),

    // [139]
    iri_reference: $ => seq(
      '<',
      /([^<>"{}|^`\\\x00-\x20])*/,
      '>'
    ),

    // [140]
    pname_ns: $ => seq(
      // TODO
      ':'
    ),

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

    // [164]
    pn_chars_base: $ => choice(
      /[A-Z]/,
      /[a-z]/,
      // TODO
    ),

    // [165]
    pn_chars_u: $ => choice(
      $.pn_chars_base,
      '_'
    ),

    // [166]
    var_name: $ => seq(
      choice(
        $.pn_chars_u,
        /[0-9]/
      ),
      // TODO
    )

  }
});
