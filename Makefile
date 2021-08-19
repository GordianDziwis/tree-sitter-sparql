build:
	./node_modules/tree-sitter-cli/tree-sitter generate
	./node_modules/tree-sitter-cli/tree-sitter test

publish: build
	npm publish

.PHONY: build publish
