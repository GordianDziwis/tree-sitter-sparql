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
      $.select_clause
      // TODO
    ),

    // [9]
    select_clause: $ => seq(
      'SELECT'
      // TODO
    ),

    // [10]
    construct_query: $ => seq(
      'CONSTRUCT',
      // TODO
    ),

    // [11]
    describe_query: $ => seq(
      'DESCRIBE',
      // TODO
    ),

    // [12]
    ask_query: $ => seq(
      'ASK',
      // TODO
    ),

    // [28]
    values_clause: $ => seq(
      'VALUES',
      // TODO
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
    ) 
  }
});
