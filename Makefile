.PHONY: build

build:
	tree-sitter generate

develop: build
	tree-sitter test
