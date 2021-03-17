build:
	tree-sitter generate
	tree-sitter test

develop:
	tree-sitter generate
	tree-sitter test

.PHONY: build develop
