
(function_call identifier: (_) @function)

(select_clause "*" @variable)

(var) @variable

(lang_tag) @iri.type

(rdf_literal 
	"^^" @iri.type
	datatype: (_)@iri.type  )

(namespace) @namespace

[
  (iri_reference)
  (prefixed_name)
] @iri

[
  "AS"
  "BASE"
  "BIND"
  "PREFIX"
  "SELECT"
  "DISTINCT"
  "REDUCED"
  "CONSTRUCT"
  "DESCRIBE"
  "ASK"
  "NOT"
  "EXISTS"
  "FROM"
  "NAMED"
  "WHERE"
  "ORDER"
  "MINUS"
  "BY"
  "ASC"
  "DESC"
  "LIMIT"
  "GROUP"
  "OFFSET"
  "OPTIONAL"
  "GRAPH"
  "UNION"
  "FILTER"
  "VALUES"
] @keyword





(string) @string

"a" @variable.builtin


(echar) @escape

(integer) @number

[
  (decimal)
  (double)
] @float

(boolean_literal) @boolean





[
  "BASE"
  "PREFIX"
] @include

[
  "ABS"
  "AVG"
  "BNODE"
  "BOUND"
  "CEIL"
  "CONCAT"
  "COALESCE"
  "CONTAINS"
  "DATATYPE"
  "DAY"
  "ENCODE_FOR_URI"
  "FLOOR"
  "HOURS"
  "IF"
  "IRI"
  "LANG"
  "LANGMATCHES"
  "LCASE"
  "MD5"
  "MINUTES"
  "MONTH"
  "NOW"
  "RAND"
  "REGEX"
  "ROUND"
  "SECONDS"
  "SHA1"
  "SHA256"
  "SHA384"
  "SHA512"
  "STR"
  "SUM"
  "MAX"
  "MIN"
  "SAMPLE"
  "GROUP_CONCAT"
  "SEPARATOR"
  "COUNT"
  "DISTINCT"
  "STRAFTER"
  "STRBEFORE"
  "STRDT"
  "STRENDS"
  "STRLANG"
  "STRLEN"
  "STRSTARTS"
  "STRUUID"
  "TIMEZONE"
  "TZ"
  "UCASE"
  "URI"
  "UUID"
  "YEAR"
  "isBLANK"
  "isIRI"
  "isLITERAL"
  "isNUMERIC"
  "isURI"
  "sameTerm"
] @function.builtin


[
  "."
  ","
  ";"
] @delimiter

[
  "("
  ")"
  "["
  "]"
  "{"
  "}"
] @brackett

[
  (path_mod)
  "||"
  "&&"
  "="
  "<"
  ">"
  "<="
  ">="
  "+"
  "-"
  "*"
  "/"
  "!"
  "^"
] @operator

[
  "IN"
  ("NOT" "IN")
] @operator.keyword

[
  (blank_node_label)
] @node.blank

