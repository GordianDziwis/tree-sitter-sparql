build:
	tree-sitter generate
	tree-sitter test

develop:
	tree-sitter generate
	tree-sitter test

publish: build
	npm publish

.PHONY: build develop
